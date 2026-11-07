#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a;
    if (a == 0)
    {
        cout << "Error";
        return 0;
    }

    cin >> b;
    while (b != 0)
    {
        if (a >= b)
        {
            cout << "ne vozrastaet";
            return 0;
        }
        a = b;
        cin >> b;
    }

    cout << "vozrastaet";
    return 0;
}