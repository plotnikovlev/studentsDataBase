#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <string>

// Определение структуры Student
struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Объявления (декларации) функций
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
void findStudentWithHighestGpa(const std::vector<Student>& database);
void findStudentWithLowestGpa(const std::vector<Student>& database);

#endif // DATABASE_H
