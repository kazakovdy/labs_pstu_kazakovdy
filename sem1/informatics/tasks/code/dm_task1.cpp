#include <iostream>
#include <cstdlib>
using namespace std;

// Заполнение массива
void FillArr(int* Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        Arr[i] = rand() % 100;
    }
}

void ShowArr(const int* Arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

// Увеличение массива на 1 элемент
// Arr передаётся по ссылке на указатель, чтобы можно было изменить сам адрес массива
// size передаётся по ссылке, чтобы изменить размер в вызывающей функции
void Resize(int*& Arr, int& size)
{
    int* newArr = new (nothrow) int[size + 1];  
    if (!newArr)
    {
        cout << "Error memory";
        return;
    }
    for (int i = 0; i < size; i++)              
    {
        newArr[i] = Arr[i];
    }
    delete[] Arr;
    Arr = newArr;
    size++;
}

// Уменьшение массива на 1 элемент
void Shrink(int*& Arr, int& size)
{
    if (size <= 1)                             
    {
        cout << "Cannot shrink array" << endl;
        return;
    }
    int* newArr = new (nothrow) int[size - 1]; 
    if (!newArr)
    {
        cout << "Error memory";
        return;
    }
    for (int i = 0; i < size - 1; i++)       
    {
        newArr[i] = Arr[i];
    }
    delete[] Arr;                           
    Arr = newArr;                             
    size--;                                      
}

int main()
{
    int size = 5;
    int* arr = new (nothrow) int[size];     
    if (!arr)
    {
        cout << "Error memory";
        return 1;
    }
    FillArr(arr, size);
    ShowArr(arr, size);

    Shrink(arr, size);                      
    ShowArr(arr, size);                         

    delete[] arr;                           
    arr = nullptr;
    return 0;
}