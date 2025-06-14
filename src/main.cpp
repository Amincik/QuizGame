#include "Quiz.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

int main() {
    std::cout << "Выберите уровень сложности викторины:\n";
    std::cout << "1) Легкий\n2) Средний\n3) Сложный\n";
    int diff_choice;
    std::cin >> diff_choice;

    Difficulty difficulty = Difficulty::Easy;
    if (diff_choice == 2) difficulty = Difficulty::Medium;
    else if (diff_choice == 3) difficulty = Difficulty::Hard;

    std::vector<Question> questions = {
        {"Столица Франции?", {"Берлин", "Париж", "Мадрид", "Рим"}, 1, Difficulty::Easy},
        {"2+2 равно?", {"3", "4", "5", "22"}, 1, Difficulty::Easy},
        {"Цвет неба?", {"Зелёный", "Красный", "Синий", "Жёлтый"}, 2, Difficulty::Easy},
        {"Кто написал 'Войну и мир'?", {"Достоевский", "Толстой", "Пушкин", "Гоголь"}, 1, Difficulty::Medium},
        {"Какая планета ближе всех к Солнцу?", {"Венера", "Земля", "Меркурий", "Марс"}, 2, Difficulty::Medium},
        {"Сколько часов в сутках?", {"12", "24", "48", "36"}, 1, Difficulty::Medium},
        {"Какой язык используется для создания этой программы?", {"Python", "C++", "Java", "Rust"}, 1, Difficulty::Hard},
        {"Сколько дней в году?", {"365", "360", "366", "364"}, 0, Difficulty::Hard}
    };

    std::cout << "Количество вопросов: " << questions.size() << std::endl;
    std::cout << "Дата начала: ";
    time_t now = time(0);
    std::cout << ctime(&now);

    Quiz quiz(questions, difficulty);
    quiz.run();

    std::cout << "Дата завершения: ";
    now = time(0);
    std::cout << ctime(&now);

    return 0;
}
