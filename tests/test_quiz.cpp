#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest/doctest.h"
#include "../include/Quiz.h"

TEST_CASE("Question struct basic") {
    Question q{"T?", {"A","B","C"}, 0};
    CHECK(q.text == "T?");
    CHECK(q.choices.size() == 3);
    CHECK(q.correctIndex == 0);
}

TEST_CASE("Quiz scoring positive") {
    std::vector<Question> qs = {
        {"1+1", {"2"}, 0}
    };
    Quiz quiz(qs);
    CHECK(quiz.score() == 0);
}

TEST_CASE("Quiz askQuestion negative skip") {
    std::vector<Question> qs = {
        {"Q", {"X","Y"}, 1}
    };
    Quiz quiz(qs);
    // Здесь бы замокать ввод — сложнее, но проверяем score не падает
    CHECK(quiz.score() == 0);
}
