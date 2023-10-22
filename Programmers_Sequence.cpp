#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;

    for (int StartIndex = 0; StartIndex < sequence.size(); StartIndex++)
    {
        int temp = k;

        for (int EndIndex = StartIndex; EndIndex < sequence.size(); EndIndex++)
        {
            temp -= sequence[EndIndex];

            if (temp == 0)
            {
                if (answer.empty())
                    answer = { StartIndex, EndIndex };
                else if ((EndIndex - StartIndex) < (answer.back() - answer.front()))
                    answer = { StartIndex, EndIndex };

                break;
            }
            else if (temp < 0)
                break;
        }
    }

    return answer;
}

int main()
{
    //vector<int> print = solution({ 1, 2, 3, 4, 5 }, 7);

    vector<int> test = { 1, 2 };

    cout << test.front() << ", " << test.back();

}