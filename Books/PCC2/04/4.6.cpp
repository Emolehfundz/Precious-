#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010, UP = 1000000;

void display(int data[], int n)
{
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;
}

// 获取给定数指定位置的数字。
int getDigitAtIndex(int number, int index)
{
    while (number > 0 && index > 0)
    {
        number /= 10;
        index--;
    }
    return number % 10;
}

void radixSort2(int data[], int n, int digits)
{
    int *bucket[10];

    for (int i = 0; i < 10; i++)
    {
        bucket[i] = new int[n + 1];
        bucket[i][0] = 0;
    }

    for (int index = 0; index < digits; index++)
    {
        for (int i = 0; i < n; i++)
        {
            int digit = getDigitAtIndex(data[i], index);
            bucket[digit][++bucket[digit][0]] = data[i];
        }
        
        for (int i = 0, j = 0; i < 10; i++)
        {
            int k = 1;
            while (k <= bucket[i][0])
                data[j++] = bucket[i][k++];
            bucket[i][0] = 0;
        }
    }

    for (int i = 0; i < 10; i++) delete [] bucket[i];
}

// 使用计数排序的变种对数组按指定位置排序。
void countingSort2(int data[], int n, int index)
{
    int *bucket = new int[10], *sorted = new int[n];

    for (int i = 0; i < 10; i++)
        bucket[i] = 0;

    for (int i = 0; i < n; i++)
        bucket[getDigitAtIndex(data[i], index)]++;

    for (int i = 1; i < 10; i++)
        bucket[i] += bucket[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = getDigitAtIndex(data[i], index);
        sorted[bucket[digit] - 1] = data[i];
        bucket[digit]--;
    }

    for (int i = 0; i < n; i++)
        data[i] = sorted[i];

    delete [] bucket, sorted;
}

void radixSort(int data[], int n, int digits)
{
    for (int index = 0; index < digits; index++) countingSort2(data, n, index);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int data[MAXN];
    for (int i = 0; i < MAXN; i++)  data[i] = rand() % UP;

    display(data, MAXN);
    radixSort(data, MAXN, 6);
    //radixSort2(data, MAXN, 6);
    display(data, MAXN);

    return 0;
}
