#include <iostream>
using namespace std;
#include <clocale>

int f1(int stroka, int stolb, int matrix[5][5])
{
    bool f = true;
    for (int i = 0;i < 5;i++)
    {
        if ((i != stroka) && (matrix[i][stolb] >= matrix[stroka][stolb]))
        {
            f = false;
        }
    }
    for (int j = 0;j < 5;j++)
    {
        if ((j != stolb) && (matrix[stroka][j] <= matrix[stroka][stolb]))
        {
            f = false;
        }
    }
    return f;
}
int f2(int stroka, int stolb, int matrix[5][5])
{
    bool f = true;
    for (int i = 0;i < stroka;i++)
    {
        if ((i != stroka) && (matrix[i][stolb] <= matrix[stroka][stolb]))
        {
            f = false;
        }
    }
    for (int j = 0;j < stolb;j++)
    {
        if ((j != stolb) && (matrix[stroka][j] >= matrix[stroka][stolb]))
        {
            f = false;
        }
    }
    return f;
}

int main()
{
    setlocale(LC_ALL, ".UTF-8");
    int matrix[5][5] = {
    {1,  2,  3,  4,  10},
    {5,  6,  7,  8,  9},
    {20, 15, 12, 11, 13},
    {3,  4,  5,  6,  7},
    {30, 25, 22, 21, 23}
    };
    cout << "Исходная матрица:" << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Определение всех седловых точек массива [5][5] " << endl;
    for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 5;j++)
        {
            if (f1(i,j,matrix) | f2(i, j, matrix))
            {
                cout << i << ';'<< j << " - Седловая точка" << endl;
            }
        }
    }
    return 0;
}
