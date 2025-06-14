cmake_minimum_required(VERSION 3.10)
project(QuizGame VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(Quiz STATIC src/Quiz.cpp)

add_executable(quiz_app src/main.cpp)
target_link_libraries(quiz_app PRIVATE Quiz)

include_directories(external/doctest)
add_executable(test_quiz tests/test_quiz.cpp)
target_link_libraries(test_quiz PRIVATE Quiz)

enable_testing()
add_test(NAME quiz_tests COMMAND test_quiz)
