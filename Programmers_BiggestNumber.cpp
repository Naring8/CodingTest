// Start (2023-10-25 17:31)
// End (2023-10-25 18:10)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) 
{
    if (a + b > b + a)
        return true;
    else
        return false;
}

string solution(vector<int> numbers)
{
    string answer = "";

    vector<string> strArr;

    for (auto& i : numbers)
        strArr.push_back(to_string(i));

    sort(strArr.begin(), strArr.end(), cmp);

    for (auto& str : strArr)
        answer += str;     

    if (answer[0] == '0')
        return "0";

    return answer;
}

/*int FirstNumber(int Num)
{
    while (Num > 9)
        Num /= 10;

    return Num;
}

bool Check(int a, int b)
{
    while (FirstNumber(a) == FirstNumber(b))
    {
        a %= 10;
        b %= 10;
    }

    return FirstNumber(a) > FirstNumber(b);
}

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), Check);
    
    for (auto& i : numbers)
        answer += to_string(i);

    return answer;
}*/

int main()
{
    cout << solution({ 6, 10, 2 }) << "\n";
    cout << solution({ 3, 30, 34, 5, 9 }) << "\n";

	return 0;
}