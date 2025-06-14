#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>

/// \brief Структура одного вопроса викторины
struct Question {
    std::string text;                  ///< Текст вопроса
    std::vector<std::string> choices; ///< Варианты ответов
    int correctIndex;                 ///< Индекс правильного варианта
};

/// \brief Основной класс викторины
class Quiz {
public:
    /// \brief Конструктор викторины
    /// \param qs Список вопросов
    Quiz(const std::vector<Question>& qs);

    /// \brief Запускает викторину (вопросы с таймером)
    void run();

    /// \brief Получает количество правильных ответов
    /// \return Число правильных ответов
    int score() const;

private:
    std::vector<Question> questions_; ///< Вопросы викторины
    int correctCount_ = 0;            ///< Счётчик правильных ответов

    /// \brief Задаёт один вопрос, показывает варианты, ждёт ответ
    /// \param q Вопрос
    void askQuestion(const Question& q);

    /// \brief Таймер ожидания (вшеллл)
    /// \param durationSec Время ожидания в секундах
    void startTimer(int durationSec) const;
};

#endif // QUIZ_H