#include <iostream>
using namespace std;

//输出一个爱心
int main()
{
    int i, j, k;
    for (i = 0; i <= 4; i++)
    {
        for (j = 0; j <= 4 - i; j++)
            cout << " ";
        for (k = 0; k <= 2 * i; k++)
            cout << "*";
        cout << endl;
    }
    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= i + 1; j++)
            cout << " ";
        for (k = 0; k <= 6 - 2 * i; k++)
            cout << "*";
        cout << endl;
    }
    return 0;
}