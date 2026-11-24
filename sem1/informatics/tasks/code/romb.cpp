#include <iostream>
using namespace std;

int main()
{
    int n=11;
    int c1 = (n - 1) / 2;   // left middle column
    int c2 = n / 2;         // right middle column (equals c1 for odd n)

    for (int i = 0; i < n; i++)
    {
        int w = (i < n - 1 - i) ? i : n - 1 - i;   // distance from the top/bottom edge
        int left = c1 - w;
        int right = c2 + w;

        for (int j = 0; j < n; j++)
        {
            if (j == left || j == right)
                cout << "1 ";
            else if (j > left && j < right)
                cout << "0 ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    return 0;
}