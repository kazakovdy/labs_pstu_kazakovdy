#include <iostream>
#include <cstdlib>
using namespace std;
int** CreateMatrix(int n)
{
    int** m = new (nothrow) int*[n];             // массив указателей на строки
    if (!m) return nullptr;
    for (int i = 0; i < n; i++)
    {
        m[i] = new (nothrow) int[n];             // каждая строка - отдельный массив
        if (!m[i])
        {
            for (int j = 0; j < i; j++) delete[] m[j];   // откат: освобождаем уже созданное
            delete[] m;
            return nullptr;
        }
    }
    return m;
}
void DeleteMatrix(int**m,int n)
{
    for (int i=0;i<n;i++) delete[] m[i];
    delete[] m;
}
void FillMatrix(int** m, int n)
{
    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            m[i][j]=rand() %99 + 1;
}
void ShowMatrix(int** m,int n)
{
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void ZeroDiagonal(int** m, int n)
{
    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;                             // главная диагональ: строка = столбец
        m[i][n - 1 - i] = 0;                     // побочная диагональ: столбец = n-1-строка
    }
}
int main()
{
    int n = 5;
    int** matrix = CreateMatrix(n);
    if (!matrix)
    {
        cout << "Error memory";
        return 1;
    }

    FillMatrix(matrix, n);
    cout << "Before:" << endl;
    ShowMatrix(matrix, n);

    ZeroDiagonal(matrix, n);
    cout << "After:" << endl;
    ShowMatrix(matrix, n);

    DeleteMatrix(matrix, n);
    matrix = nullptr;
    return 0;
}