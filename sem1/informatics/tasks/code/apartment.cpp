#include <iostream>
#include <string>
using namespace std;

struct Apartment
{
    int price;
    int floor;
    double size;
    string street;
};

int main()
{
    Apartment v[3]; // Создание массива структур на 3 элемента
    for (int i = 0; i < 3; i++) // Поочерёдно заполняем каждую структуру
    {
        cout << "Квартира " << i + 1 << endl;
        cout << "Цена за квартиру: ";
        cin >> v[i].price;
        cout << "Этаж: ";
        cin >> v[i].floor;
        cout << "Площадь квартиры: ";
        cin >> v[i].size;
        cout << "Улица и номер дома: ";
        cin >> ws;                // пропускаем перенос строки и пробелы после cin >>
        getline(cin, v[i].street); // читаем строку целиком, с пробелами
        cout << endl;
    }

    int target_price;
    cout << "\n\nЗа какую цену вы ищите квартиру: ";
    cin >> target_price; // Интересующая нас цена квартиры

    bool found = false;
    for (int i = 0; i < 3; i++)
    {
        if (target_price == v[i].price) // Сравниваем интересующую цену с реальными ценами
        {
            cout << "Цена за квартиру: " << v[i].price << endl;
            cout << "Этаж: " << v[i].floor << endl;
            cout << "Площадь квартиры: " << v[i].size << endl;
            cout << "Улица и номер дома: " << v[i].street << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Квартир с такой ценой не найдено" << endl;

    return 0;
}