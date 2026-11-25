#include <iostream>
using namespace std;

const int N = 7;

int main()
{
    int a[N][N];
    int c = N / 2;
    for (int i = 0; i < N; i++)
    {
        int w = i < N - 1 - i ? i : N - 1 - i;
        for (int j = 0; j < N; j++)
        {
            int d = j > c ? j - c : c - j;
            if (d == w)     a[i][j] = 1;
            else if (d < w) a[i][j] = 0;
            else            a[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (a[i][j] == -1) cout << "  ";
            else               cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}