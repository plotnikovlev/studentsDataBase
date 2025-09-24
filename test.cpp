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


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
