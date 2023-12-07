// 20:02 ~ 20:22 Æ÷±â
#include <iostream>

using namespace std;

int GCD(int a, int b) 
{
	while (b != 0) 
	{
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

long long solution(int w, int h) 
{
    long long answer = ((long long)w * h) - (w + h - GCD(w, h));

    return answer;
}

int main()
{
    cout << solution(8, 12);

    return 0;
}