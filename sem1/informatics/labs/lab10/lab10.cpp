// Сформировать двумерный массив. Удалить из него строку с заданным номером.
#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

void printMatrix(int** m, int stroka, int stolbec)
{
    for (int i = 0; i < stroka; i++)
    {
        for (int j = 0; j < stolbec; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void FillMatrix(int** m, int stroka, int stolbec)
{
    for (int i = 0; i < stroka; i++)
    {
        for (int j = 0; j < stolbec; j++)
        {
            m[i][j] = rand() % 99 + 1;
        }
    }
}

int** CreateMatrix(int stroka, int stolbec)
{
    int** m = new(nothrow) int*[stroka];
    if (!m) return nullptr;
    for (int i = 0; i < stroka; i++)
    {
        m[i] = new(nothrow) int[stolbec];
        if (!m[i])
        {
            for (int j = 0; j < i; j++) delete[] m[j];
            delete[] m;
            return nullptr;
        }
    }
    return m;
}

void DeleteMatrix(int** m, int stroka)
{
    for (int i = 0; i < stroka; i++) delete[] m[i];
    delete[] m;
}

// Удаляет строку с номером k (нумерация с 1), возвращает новый массив.
// Старый массив указателей освобождается, stroka уменьшается на 1.
int** DeleteTask(int** m, int& stroka, int k)
{
    int** res = new(nothrow) int*[stroka - 1];
    if (!res) return nullptr;      // старый массив при этом не тронут
    int r = 0;
    for (int i = 0; i < stroka; i++)
    {
        if (i == k - 1)
            delete[] m[i];         // удаляемая строка
        else
            res[r++] = m[i];       // остальные строки переходят в новый массив
    }
    delete[] m;
    stroka--;
    return res;
}

int main()
{
    int stroka, stolbec;
    cout << "Введите количество строк и столбцов" << endl;
    cin >> stroka >> stolbec;
    int** matrix = CreateMatrix(stroka, stolbec);
    if (!matrix)
    {
        cout << "Не удалось выделить память" << endl;
        return 1;
    }

    FillMatrix(matrix, stroka, stolbec);
    cout << "Исходный массив:" << endl;
    printMatrix(matrix, stroka, stolbec);

    int k;
    cout << "Номер удаляемой строки ";
    cin >> k;
    int** result = DeleteTask(matrix, stroka, k);
    matrix = result;

    cout << "Массив после удаления строки:" << endl;
    printMatrix(matrix, stroka, stolbec);

    DeleteMatrix(matrix, stroka);
    return 0;
}
