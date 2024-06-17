#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int p[3] = { 0, 0, 0 };
    int p2[4] = { 1, 3, 4, 5 };
    int p3[5] = { 3, 1, 2, 4, 5 };

    for (int i = 0; i < answers.size(); i++)
    {
        // p1
        {
            if (answers[i] == ((i % 5) + 1))
                ++p[0];
        }
        // p2
        {
            if (i & 1) //  홀수
            {
                if (answers[i] == p2[((i / 2) % 4)])
                    ++p[1];
            }
            else
            {
                if (answers[i] == 2)
                    ++p[1];
            }
        }
        // p3
        {
            if (answers[i] == p3[(i / 2) % 5])
                ++p[2];
        }
    }
    int mVal = max(max(p[0], p[1]), p[2]);
    // algorithm 라이브러리에 있는 max_element 함수
    //int maxVal = *max_element(p, p + 3);

    for (int i = 0; i < 3; i++)
    {
        if (p[i] == mVal)
            answer.push_back(i + 1);
    }

    return answer;
}

int main()
{
    for (auto& i : solution({ 1, 2, 3, 4, 5 }))
    {
        cout << i << " ";
    }
    cout << "\n";
    for (auto& i : solution({ 1, 3, 2, 4, 2 }))
    {
        cout << i << " ";
    }

}