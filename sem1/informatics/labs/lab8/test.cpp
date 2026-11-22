// Сформировать двоичный файл из элементов, заданной в ва-рианте структуры, распечатать его содержимое, выполнить удаление
// и добавление элементов в соответствии со своим вариантом, используя для поиска удаляемых или 
// добавляе-мых элементов функцию. Формирование, печать, добавление и удаление элементов оформить в виде функций. 
// Преду-смотреть сообщения об ошибках при открытии файла и вы-полнении операций ввода/вывода.
// 6.	 Структура "Школьник":
// -	фамилия, имя, отчество;
// -	класс;
// -	номер телефона;
// -	оценки по предметам (математика, физика, русский язык, литература).
// Удалить все элементы, у которых есть 2 хотя бы по одно-му предмету, добавить элемент в начало файла.
// Лабораторная работа №8. Вариант 6. Структура "Школьник".
// Удалить всех, у кого есть двойка, добавить элемент в начало файла.

#include <iostream>
#include <cstdio>
using namespace std;

struct Student {
    char surname[30];
    char name[30];
    char patronymic[30];
    int  klass;
    char phone[20];
    int  marks[4];      // математика, физика, русский, литература
};

// ввод одного школьника
void input(Student& s)
{
    cout << "Фамилия Имя Отчество: ";
    cin >> s.surname >> s.name >> s.patronymic;
    cout << "Класс: ";
    cin >> s.klass;
    cout << "Телефон: ";
    cin >> s.phone;
    cout << "Оценки (математика физика русский литература): ";
    for (int i = 0; i < 4; i++)
        cin >> s.marks[i];
}

// вывод одного школьника
void printOne(Student& s)
{
    cout << s.surname << " " << s.name << " " << s.patronymic
         << ", класс " << s.klass << ", тел. " << s.phone << ", оценки:";
    for (int i = 0; i < 4; i++)
        cout << " " << s.marks[i];
    cout << endl;
}

//есть ли хотя бы одна двойка
bool hasTwo(Student& s)
{
    for (int i = 0; i < 4; i++)
        if (s.marks[i] == 2) return true;
    return false;
}

// формирование файла
void create()
{
    FILE* f = fopen("students.dat", "wb");
    int n;
    cout << "Сколько школьников? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Student s;
        input(s);
        fwrite(&s, sizeof(Student), 1, f);
    }
    fclose(f);
}

// печать файла
void print()
{
    FILE* f = fopen("students.dat", "rb");
    Student s;
    cout << "--- Файл ---" << endl;
    while (fread(&s, sizeof(Student), 1, f) == 1)
        printOne(s);
    fclose(f);
}

// удаление: переписываем во временный файл всех, кроме тех, у кого есть двойка
void removeBad()
{
    FILE* in  = fopen("students.dat", "rb");
    FILE* out = fopen("tmp.dat", "wb");
    Student s;
    while (fread(&s, sizeof(Student), 1, in) == 1)
        if (!hasTwo(s))
            fwrite(&s, sizeof(Student), 1, out);
    fclose(in);
    fclose(out);
    remove("students.dat");
    rename("tmp.dat", "students.dat");
}

// добавление в начало: сначала новая запись, потом все старые
void addToStart()
{
    FILE* in  = fopen("students.dat", "rb");
    FILE* out = fopen("tmp.dat", "wb");
    Student s;
    input(s);
    fwrite(&s, sizeof(Student), 1, out);
    while (fread(&s, sizeof(Student), 1, in) == 1)
        fwrite(&s, sizeof(Student), 1, out);
    fclose(in);
    fclose(out);
    remove("students.dat");
    rename("tmp.dat", "students.dat");
}

int main()
{
    setlocale(LC_ALL, "rus");

    create();
    print();

    removeBad();
    print();

    cout << "Новый школьник (в начало):" << endl;
    addToStart();
    print();

    return 0;
}
