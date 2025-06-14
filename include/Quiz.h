#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>

/**
 * @brief Структура одного вопроса викторины
 */
struct Question {
    std::string text;                    ///< Текст вопроса
    std::vector<std::string> options;   ///< Варианты ответов
    int correctOptionIndex;             ///< Индекс правильного варианта (с 0)
};

/**
 * @brief Основной класс викторины
 */
class Quiz {
public:
    /**
     * @brief Конструктор викторины
     * @param qs Список вопросов
     */
    Quiz(const std::vector<Question>& qs);

    /**
     * @brief Запускает викторину
     */
    void run();

    /**
     * @brief Получает количество правильных ответов
     * @return Число правильных ответов
     */
    int getScore() const;

private:
    std::vector<Question> questions;  ///< Список вопросов
    int score = 0;                    ///< Счётчик правильных ответов
    const int timeLimit = 10;        ///< Ограничение времени на ответ (сек)

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
