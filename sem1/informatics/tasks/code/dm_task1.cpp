#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;

// Заполнение массива случайными числами от 0 до 99
void FillArr(int* Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        Arr[i] = rand() % 100;
    }
}

// Вывод массива и его размера
void ShowArr(const int* Arr, int size)
{
    cout << "Массив (размер " << size << "): ";
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

// Увеличение массива на 1 элемент (новый элемент = 0)
void Resize(int*& Arr, int& size)
{
    int* newArr = new (nothrow) int[size + 1];
    if (!newArr)
    {
        cout << "Ошибка: не удалось выделить память" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        newArr[i] = Arr[i];
    }
    newArr[size] = 0;
    delete[] Arr;
    Arr = newArr;
    size++;
}

// Уменьшение массива на 1 элемент (последний элемент удаляется)
void Shrink(int*& Arr, int& size)
{
    if (size <= 1)
    {
        cout << "Нельзя уменьшить массив: остался один элемент" << endl;
        return;
    }
    int* newArr = new (nothrow) int[size - 1];
    if (!newArr)
    {
        cout << "Ошибка: не удалось выделить память" << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        newArr[i] = Arr[i];
    }
    delete[] Arr;
    Arr = newArr;
    size--;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));

    int size = 5;
    int* arr = new (nothrow) int[size];
    if (!arr)
    {
        cout << "Ошибка: не удалось выделить память" << endl;
        return 1;
    }

    cout << "=== Динамический массив: изменение размера ===" << endl << endl;

    cout << "1. Создаём массив из " << size << " элементов и заполняем случайными числами:" << endl;
    FillArr(arr, size);
    ShowArr(arr, size);
    cout << endl;

    cout << "2. Увеличиваем массив на 1 элемент (новый элемент будет равен 0):" << endl;
    Resize(arr, size);
    ShowArr(arr, size);
    cout << endl;

    cout << "3. Уменьшаем массив на 1 элемент (последний элемент удаляется):" << endl;
    Shrink(arr, size);
    ShowArr(arr, size);
    cout << endl;

    cout << "4. Освобождаем память." << endl;
    delete[] arr;
    arr = nullptr;

    cout << "Готово." << endl;
    return 0;
}