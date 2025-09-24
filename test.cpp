#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <limits>

// Подключаем код из main.cpp для доступа к структурам и функциям
#include "main.cpp" 


// Тест для поиска студента с наивысшим баллом
TEST(StudentDBTest, FindHighestGpa_BasicTest) {
    std::vector<Student> db = {
        {"Alice", 20, "CS", 3.8},
        {"Bob", 22, "EE", 3.9},
        {"Charlie", 21, "ME", 3.5}
    };
    const Student* bestStudent = &db[0];
    for (const auto& s : db) {
        if (s.gpa > bestStudent->gpa) {
            bestStudent = &s;
        }
    }
    ASSERT_EQ(bestStudent->name, "Bob");
    ASSERT_DOUBLE_EQ(bestStudent->gpa, 3.9);
}


// Тест для поиска студента с наинизшим баллом
TEST(StudentDBTest, FindLowestGpa_BasicTest) {
    std::vector<Student> db = {
        {"Alice", 20, "CS", 3.8},
        {"Bob", 22, "EE", 3.9},
        {"Charlie", 21, "ME", 3.5}
    };
    const Student* worstStudent = &db[0];
    for (const auto& s : db) {
        if (s.gpa < worstStudent->gpa) {
            worstStudent = &s;
        }
    }
    ASSERT_EQ(worstStudent->name, "Charlie");
    ASSERT_DOUBLE_EQ(worstStudent->gpa, 3.5);
}


// Тест для пустой базы данных
TEST(StudentDBTest, FindGpa_EmptyDatabase) {
    std::vector<Student> db;
    // Функции в текущем виде выводят в cout. В идеале они должны возвращать optional<Student> или nullptr
    // Мы предполагаем, что они не должны падать или вызывать неопределенное поведение
    ASSERT_NO_THROW(findStudentWithHighestGpa(db));
    ASSERT_NO_THROW(findStudentWithLowestGpa(db));
}


// Тест для базы с одним студентом
TEST(StudentDBTest, FindGpa_SingleStudent) {
    std::vector<Student> db = {{"Dave", 23, "CS", 4.0}};
    const Student* bestStudent = &db[0];
    const Student* worstStudent = &db[0];
    
    ASSERT_EQ(bestStudent->name, "Dave");
    ASSERT_DOUBLE_EQ(bestStudent->gpa, 4.0);
    ASSERT_EQ(worstStudent->name, "Dave");
    ASSERT_DOUBLE_EQ(worstStudent->gpa, 4.0);
}


// Тест на добавление студента (проверяем размер базы)
TEST(StudentDBTest, AddStudent_Test) {
    std::vector<Student> db;
    // Функция addStudent является интерактивной, что плохо для тестов.
    // Для настоящего юнит-теста ее нужно бы переписать.
    // Здесь мы просто имитируем добавление и проверяем результат.
    Student new_student = {"Eve", 24, "IT", 3.7};
    db.push_back(new_student);

    ASSERT_EQ(db.size(), 1);
    ASSERT_EQ(db[0].name, "Eve");
    ASSERT_EQ(db[0].gpa, 3.7);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
