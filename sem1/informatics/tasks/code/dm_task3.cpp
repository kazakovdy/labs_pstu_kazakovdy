//четные элементы в соседнем массиве 
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    cout<<"Введите n ";
    cin>>n;
    int* m=new int[n];
    for (int i=0;i<n;i++)
    {
        m[i]=rand()%100+1;
    }
    cout<<"Массив до"<<endl;
    for (int i=0;i<n;i++)
    cout<<m[i]<<" ";
    for (int i=1;i<n;i++)
    {
        if (m[i]%2==0)
        {
            if (i==0 || i==n-1) m[i]=0;
            else m[i]=m[i-1]+m[i+1];
        }
    }
    cout<<endl<<"Массив после "<<endl;
    for (int i=0;i<n;i++)
    cout<<m[i]<<" ";
    return 0;

}