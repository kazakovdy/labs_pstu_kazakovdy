#include <iostream>
#include <string>
using namespace std;
struct Student {
    string name;   // имя
    int age;       // возраст
    int grade;     // курс
};
// создание
// Значения после "=" - это значения по умолчанию:
// если при вызове что-то не передать, подставится оно.
Student makeStudent(string name = "Ivan", int age = 21, int grade = 4) {
    Student s;          // пустая заготовка
    s.name = name;      // заполняем поля
    s.age = age;
    s.grade = grade;
    return s;           // отдаём готовую структуру наружу
}
//вывод
// Принимает структуру целиком, поэтому не нужно передавать три поля по отдельности.
// const Student& - читаем оригинал без копирования и не можем его изменить.
void printStudent(const Student& s) {
    cout << "Name: "  << s.name  << endl;
    cout << "Age: "   << s.age   << endl;
    cout << "Grade: " << s.grade << endl;
}
//Использование 
int main() {
    // Вызываем функцию-создатель, результат кладём в переменную a.
    Student a = makeStudent("Victor", 17, 3);

    // Передаём студента в функцию печати.
    printStudent(a);

    return 0;
}