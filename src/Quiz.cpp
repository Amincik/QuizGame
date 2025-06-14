#include "Quiz.h"
#include <iostream>
#include <chrono>
#include <thread>

Quiz::Quiz(const std::vector<Question>& qs) : questions_(qs) {}

void Quiz::run() {
    for (const auto& q : questions_) {
        askQuestion(q);
    }
    std::cout << "Вы прошли викторину! Правильных ответов: "
              << correctCount_ << " из " << questions_.size() << std::endl;
}

int Quiz::score() const {
    return correctCount_;
}

void Quiz::askQuestion(const Question& q) {
    std::cout << "\nВопрос: " << q.text << std::endl;
    for (size_t i = 0; i < q.choices.size(); ++i) {
        std::cout << i + 1 << ") " << q.choices[i] << std::endl;
    }
    startTimer(10);
    int answer;
    if (!(std::cin >> answer)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Неверный ввод, считаю неправильным." << std::endl;
    } else if (answer - 1 == q.correctIndex) {
        std::cout << "Правильно!" << std::endl;
        ++correctCount_;
    } else {
        std::cout << "Неправильно. Правильный ответ: " << q.choices[q.correctIndex] << std::endl;
    }
}

void Quiz::startTimer(int durationSec) const {
    using namespace std::chrono;
    auto start = steady_clock::now();
    std::cout << "У вас есть " << durationSec << " секунд на ответ..." << std::endl;
    while (duration_cast<seconds>(steady_clock::now() - start).count() < durationSec) {
        std::this_thread::sleep_for(milliseconds(200));
    }
    std::cout << "\nВремя вышло!" << std::endl;
}
