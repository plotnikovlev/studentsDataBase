#include "database.h" // Подключаем наш заголовочный файл

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    if (database.empty()) {
        std::cout << "База данных пуста.\n\n";
        return;
    }
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Функция для поиска студента с наивысшим средним баллом
void findStudentWithHighestGpa(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }

    const Student* bestStudent = &database[0];
    for (const Student& student : database) {
        if (student.gpa > bestStudent->gpa) {
            bestStudent = &student;
        }
    }

    std::cout << "Студент с наивысшим средним баллом:\n";
    std::cout << "Имя: " << bestStudent->name << "\n";
    std::cout << "Средний балл: " << bestStudent->gpa << "\n\n";
}

// Функция для поиска студента с наинизшим средним баллом
void findStudentWithLowestGpa(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }

    const Student* worstStudent = &database[0];
    for (const Student& student : database) {
        if (student.gpa < worstStudent->gpa) {
            worstStudent = &student;
        }
    }

    std::cout << "Студент с наинизшим средним баллом:\n";
    std::cout << "Имя: " << worstStudent->name << "\n";
    std::cout << "Средний балл: " << worstStudent->gpa << "\n\n";
}
