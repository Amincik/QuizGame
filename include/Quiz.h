#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>

/**
 * @brief Уровень сложности вопроса
 */
enum class Difficulty {
    Easy,
    Medium,
    Hard
};

/**
 * @brief Структура одного вопроса викторины
 */
struct Question {
    std::string text;                    ///< Текст вопроса
    std::vector<std::string> options;   ///< Варианты ответов
    int correctOptionIndex;              ///< Индекс правильного варианта (с 0)
    Difficulty difficulty;               ///< Уровень сложности вопроса
};

/**
 * @brief Основной класс викторины
 */
class Quiz {
public:
    /**
     * @brief Конструктор викторины
     * @param qs Список вопросов
     * @param diff Уровень сложности викторины
     */
    Quiz(const std::vector<Question>& qs, Difficulty diff);

    /**
     * @brief Запускает викторину
     */
    void run();

    /**
     * @brief Получает количество набранных очков
     * @return Количество очков
     */
    int getScore() const;

private:
    std::vector<Question> questions;  ///< Список вопросов
    int score = 0;                    ///< Счётчик очков
    int currentQuestionIndex = 0;     ///< Текущий вопрос
    int timeLimit = 10;               ///< Время на ответ (сек)

    Difficulty quizDifficulty;        ///< Выбранный уровень сложности викторины

    /**
     * @brief Обрабатывает один вопрос, выводит и ждёт ответ
     * @param question Вопрос
     */
    void askQuestion(const Question& question);

    /**
     * @brief Показывает итог викторины
     */
    void showResult();
};

/**
 * @brief Форматирует время в строку вида "X мин Y сек"
 * @param seconds Количество секунд
 * @return Отформатированная строка
 */
std::string formatTime(int seconds);

#endif // QUIZ_H
