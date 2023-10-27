// Start (2023-10-27 20 : 51)
// End   (2023-10-27 22 : 00)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); i++)
        if (citations[i] >= i + 1)
            answer = i + 1;

    return answer;
}

int main()
{
    cout << solution({ 3, 0, 6, 1, 5 });

    return 0;
}