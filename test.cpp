#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <limits>

// Подключаем код из main.cpp для доступа к структурам и функциям
#include "main.cpp" 

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
