#include <iostream>
using namespace std;

const int N = 7;
int main()
{
    int a[N][N];
    int c1 = (N - 1) / 2;
    int c2 = N / 2;
    for (int i = 0; i < N; i++)
    {
        // расстояние от строки до верхнего или нижнего края
        int w;
        if (i < N - 1 - i)
            w = i;
        else
            w = N - 1 - i;

        int left = c1 - w;
        int right = c2 + w;

        for (int j = 0; j < N; j++)
        {
            if (j == left || j == right)
                a[i][j] = 1;      // контур
            else if (j > left && j < right)
                a[i][j] = 0;      // внутри
            else
                a[i][j] = -1;     // снаружи
        }
    }

    // вывод
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] == -1)
                cout << "  ";
            else
                cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}