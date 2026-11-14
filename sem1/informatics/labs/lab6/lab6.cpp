//6. 	Преобразовать строку таким образом, чтобы сначала в ней были напечатаны только буквы, а потом только циф-ры, не меняя порядка следования символов в строке.
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    cout << "Enter string: ";
    char s1[256];
    string s2, s3;
    cin.getline(s1, 256);
    for (int i = 0; i < strlen(s1); i++)
    {
        if (isdigit(s1[i])) s3 += s1[i];
        else if (isalpha(s1[i])) s2 += s1[i];
    }
    cout << s2 + s3 << endl;
}