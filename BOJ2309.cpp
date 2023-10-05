// 시작 시간 (2023-10-05 20:08)
// 종료 시간 (2023-10-05 21:03) 포기

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
        }
            
    }   // input

    for (int i = 0; i < allNum; i++)
    {
        int checkNum = 100 - Height[i];


    }


    return 0;
}