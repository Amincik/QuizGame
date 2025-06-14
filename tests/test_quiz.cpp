#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Quiz.h"

TEST_CASE("Тест структуры Question") {
    Question q;
    q.text = "Сколько будет 2 + 2?";
    q.options = {"3", "4", "5"};
    q.correctOptionIndex = 1;

    CHECK(q.text == "Сколько будет 2 + 2?");
    CHECK(q.options.size() == 3);
    CHECK(q.correctOptionIndex == 1);
}

TEST_CASE("Тест конструктора Quiz") {
    std::vector<Question> questions = {
        {"Столица России?", {"Москва", "Киев", "Минск", "Астана"}, 0},
        {"Сколько дней в неделе?", {"5", "6", "7"}, 2}
    };

    Quiz quiz(questions, Difficulty::Easy); // или нужный уровень сложности
    CHECK(quiz.getScore() == 0);
}

TEST_CASE("Тест времени форматирования") {
    CHECK(formatTime(0) == "0 мин 0 сек");
    CHECK(formatTime(65) == "1 мин 5 сек");
    CHECK(formatTime(125) == "2 мин 5 сек");
}
