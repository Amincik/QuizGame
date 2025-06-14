#include "Quiz.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<Question> questions = {
        {"Столица Франции?", {"Берлин", "Париж", "Мадрид", "Рим"}, 1},
        {"2+2 равно?", {"3", "4", "5", "22"}, 1},
        {"Цвет неба?", {"Зелёный", "Красный", "Синий", "Жёлтый"}, 2}
    };

    Quiz quiz(questions);
    quiz.run();

    return 0;
}
