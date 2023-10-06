// 시작 시간 (2023-10-05 20:08)
// 종료 시간 (2023-10-05 21:03) 포기

// 2차 시도 시작(2023-10-05 23:45)
// 종료(2023-10-06 00:08) - +23분 경과

#include <iostream>

using namespace std;

const int allNum = 9;
const int Num = 7;

void Swap(int* arr, int sA, int sB) // Swap by Index
{
    if (sA == sB)
        return;

    int temp = arr[sA];
    arr[sA] = arr[sB];
    arr[sB] = temp;
}

void SortAsc(int* arr, int MaxIndex)
{
    for (int i = 0; i < MaxIndex - 1; i++)
    {
        int Min = i;    // MinNumber Index

        for (int j = i + 1; j < MaxIndex; j++)
            if (arr[Min] > arr[j])
                Min = j;

        Swap(arr, i, Min);
    }
}

// BOJ - return int
int main()
{
    int Height[allNum]; // All(9)
    int RealHeight[Num]; // D(7)

    int Sum = 0;

    for (int i = 0; i < allNum; i++)
    {
        int tempHeight;
        cin >> tempHeight;

        if (tempHeight > 0 && tempHeight < 100)
        {
            for (int j = 0; j < i; j++)
            {
                if (tempHeight == Height[j])
                    return 0;
            }

            Height[i] = tempHeight;
            Sum += tempHeight;
        }
        else
            return 0;

    }   // input

    int diff = Sum - 100;
    int diffIndex = 0;

    for (int i = 0; i < allNum - 1; i++) // Combination 9C7 -> find 100
    {
        for (int j = i + 1; j < allNum; j++)
        {
            if (Height[i] + Height[j] == diff)
            {
                for (int k = 0; k < allNum; k++)
                {
                    if (k == i || k == j)
                        continue;
                    RealHeight[diffIndex] = Height[k];
                    diffIndex++;
                }
            }
        }
    }

    SortAsc(RealHeight, Num);

    for (int i = 0; i < Num; i++)
        cout << RealHeight[i] << endl;

    return 0;
}