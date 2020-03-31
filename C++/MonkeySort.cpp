#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool isSort(int Array[], int n)
{
    while (--n >= 1)
    {
        if (Array[n] < Array[n - 1])
            return false;
    }
    return true;
}

void RandomExchange(int Array[], int n)
{
    int key, temp;
    for (int i = 0; i < n; i++)
    {
        temp = Array[i];
        key = rand() % n;
        Array[i] = Array[key];
        Array[key] = temp;
    }
}

void MonkeySort(int Array[10], int n)
{
    while (!isSort(Array, n))
        RandomExchange(Array, n);
}

int main()
{
    srand(time(NULL));
    int Array[9];
    for (int i = 0; i < 9; i++)
        Array[i] = rand() % 99 + 1;

    cout << "排序前的随机数组：\n";
    for (int i = 0; i < 9; i++)
        cout << Array[i] << " ";
    cout << endl;

    MonkeySort(Array, 9);

    cout << "排序后的随机数组：\n";
    for (int i = 0; i < 9; i++)
        cout << Array[i] << " ";
    cout << endl;
    system("pause");
    return 0;
} 