
#include <iostream>
#include <clocale>
using namespace std;

const int SIZE = 5;
int disks[3][SIZE];
int count[3] = { 0, 0, 0 };
int moves = 0;

void show()
{
    for (int i = SIZE - 1; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < count[j])
                cout << " [" << disks[j][i] << "] ";
            else
                cout << "  |  ";
        }
        cout << "\n";
    }
    cout << "  1     2     3\n";
}

void transfer(int a, int b)
{
    int from = a - 1;
    int to = b - 1;
    count[from]--;
    int disk = disks[from][count[from]];
    disks[to][count[to]] = disk;
    count[to]++;
    moves++;

    cout << "Ход " << moves << ": кольцо " << disk
         << ", " << a << " -> " << b << "\n";
    show();
    cout << "\n";
}

void solve(int n, int a, int b, int c)
{
    if (n == 1)
        transfer(a, b);
    else
    {
        solve(n - 1, a, c, b);
        transfer(a, b);
        solve(n - 1, c, b, a);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < SIZE; i++)
        disks[0][i] = SIZE - i;
    count[0] = SIZE;

    cout << "Начальное положение:\n";
    show();
    cout << "\n";

    solve(SIZE, 1, 3, 2);

    cout << "Готово! Всего ходов: " << moves << "\n";
    return 0;
}
