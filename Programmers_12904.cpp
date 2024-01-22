// Start (2024-01-22 17:11 ~
#include <iostream>
#include <string>

using namespace std;

int Palindrome(string s, int left, int right)
{
    while (left >= 0 && right < s.size())
    {
        if (s[left] != s[right])
            break;

        left--; right++;
    }

    return right - left - 1;
}

int solution(string s)
{
    int answer = 1;

    for (int i = 0; i < s.size(); i++)
    {
        int odd = Palindrome(s, i, i);
        int even = Palindrome(s, i - 1, i);

        answer = max(answer, max(odd, even));
    }

    return answer;
}

int main()
{
    cout << solution("abcdcba") << "\n";
    cout << solution("abacde") << "\n";

    return 0;
}