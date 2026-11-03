#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF8");
    const int n = 5;
    int A[n] =  {7, 3, 5, 2, 6};
    for(int i = 0; i < n - 1; ++i)
        {
            int m = i;
            for(int j = i + 1; j < n; ++j)
                {
                    if(A[m] > A[j])
                    {
                        m = j;
                    }
                }
            int t = A[i];
            A[i] = A[m];
            A[m] = t;
        }
cout << "Отсортированный массив: ";
    for (int k = 0; k < n; k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;

    return 0;
}