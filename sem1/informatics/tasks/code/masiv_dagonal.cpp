#include<iostream>
using namespace std;

int main()
{
    const int N = 5;
    int A[N][N];

    // Главная диагональ: i == j
    // Побочная диагональ: i + j == N - 1
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(i < j && i + j < N - 1)
            {
                A[i][j] = 0;
            }
            else
            {
                A[i][j] = 1;
            }
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}