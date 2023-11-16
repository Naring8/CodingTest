// Start (2023-11-16 21:15)
// End (2023-11-16 22:15)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int Max = 200000000;
const int Min = 1;

int solution(vector<int> stones, int k)
{
    int answer = 0;

    int min_weights = Max;    // 가장 작은 무게를 견디는 돌
    int max_weights = 0; // 가장 큰 무게를 견디는 돌
    for (int& stone : stones)
    {
        min_weights = min(min_weights, stone);
        max_weights = max(Max, stone);
    }

    int mid = 0;
    while (max_weights >= min_weights)
    {
        mid = (max_weights + min_weights) / 2;

        int skip_count = 0;
        int max_skip_count = 0;

        vector<int> temp = stones;
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i] -= mid;
            if (temp[i] < 0)
                skip_count++;
            else
                skip_count = 0;
            max_skip_count = max(max_skip_count, skip_count);
        }

        if (max_skip_count < k)
        {
            answer = max(answer, mid);
            min_weights = mid + 1;
        }
        else
            max_weights = mid - 1;
    }

    return answer;
}

/*int solution(vector<int> stones, int k)
{
    int answer = 0;

    int max_weights = Max; // (k == 1 / 전부 하나씩 건널 때)
    int min_weights = 0; // (k == stones.size() / 씩 건널 수 있을 때)
    for (int& stone : stones)
    {
        min_weights = max(min_weights, stone);
        max_weights = min(Max, stone);
    }

    int mid = 0;
    while (max_weights >= min_weights)
    {
        mid = (max_weights + min_weights) / 2;
    }

    return answer;
}*/

int main()
{
    cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3) << "\n";
}