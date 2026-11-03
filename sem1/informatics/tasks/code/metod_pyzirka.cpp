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
            for(int j = n - 1; j > i; j--)
                { 
                    if(A[j - 1] >A[j])
                    {
                        int t = A[j - 1];
                        A[j - 1] = A[j];
                        A[j] = t;
                    }
                }
        }
     for (int k = 0; k < n; k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;

    return 0;
}