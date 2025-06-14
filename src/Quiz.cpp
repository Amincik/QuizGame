#include "Quiz.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <limits>
#include <future>
#include <sstream>

/**
 * @brief Конструктор класса Quiz
 * @param q Вектор вопросов
 * @param diff Уровень сложности викторины
 */
Quiz::Quiz(const std::vector<Question>& q, Difficulty diff)
    : questions(q), score(0), quizDifficulty(diff) 
{
    // Устанавливаем время на ответ в зависимости от сложности
    switch (quizDifficulty) {
        case Difficulty::Easy:
            timeLimit = 15;
            break;
        case Difficulty::Medium:
            timeLimit = 10;
            break;
        case Difficulty::Hard:
            timeLimit = 7;
            break;
    }
}

/**
 * @brief Главная функция запуска викторины
 */
void Quiz::run() {
    for (const auto& question : questions) {
        askQuestion(question);
    }
    showResult();
}

/**
 * @brief Задаёт один вопрос и проверяет ответ
 * @param question Объект вопроса
 */
void Quiz::askQuestion(const Question& question) {
    std::cout << "\nВопрос: " << question.text << "\n";

    for (size_t i = 0; i < question.options.size(); ++i) {
        std::cout << i + 1 << ") " << question.options[i] << "\n";
    }

    std::cout << "У вас есть " << timeLimit << " секунд на ответ...\n";

    int userAnswer = 0;

    // Используем std::future для реализации таймера на ввод
    auto future = std::async(std::launch::async, []() {
        int input;
        std::cin >> input;
        return input;
    });

    if (future.wait_for(std::chrono::seconds(timeLimit)) == std::future_status::ready) {
        userAnswer = future.get();
    } else {
        std::cout << "\nВремя вышло!\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        return;
    }

    if (userAnswer - 1 == question.correctOptionIndex) {
        std::cout << "Правильно!\n";

        // Начисляем очки в зависимости от сложности вопроса
        switch (question.difficulty) {
            case Difficulty::Easy:
                score += 1;
                break;
            case Difficulty::Medium:
                score += 2;
                break;
            case Difficulty::Hard:
                score += 3;
                break;
        }
    } else {
        std::cout << "Неправильно! Правильный ответ: "
                  << question.options[question.correctOptionIndex] << "\n";
    }
}

/**
 * @brief Показывает итог викторины
 */
void Quiz::showResult() {
    std::cout << "\nВы прошли викторину! Ваши очки: "
              << score << " из максимальных возможных.\n";
}

/**
 * @brief Форматирует время в строку (для демонстрации дополнительного кода)
 * @param seconds Количество секунд
 * @return Строка вида "X мин Y сек"
 */
std::string formatTime(int seconds) {
    int minutes = seconds / 60;
    int secs = seconds % 60;

    std::ostringstream oss;
    oss << minutes << " мин " << secs << " сек";
    return oss.str();
}

int Quiz::getScore() const {
    return score;
}
