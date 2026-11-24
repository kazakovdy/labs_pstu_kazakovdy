#include <iostream>
using namespace std;

const int N = 7;

int main()
{
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = -1;

    int c1 = (N - 1) / 2;
    int c2 = N / 2;
    for (int i = 0; i < N; i++)
    {
        int w = (i < N - 1 - i) ? i : N - 1 - i;
        int left = c1 - w;
        int right = c2 + w;

        for (int j = left; j <= right; j++)
            a[i][j] = 0;

        a[i][left] = 1;
        a[i][right] = 1;
    }

    // вывод массива
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