// Start (2023-10-19 22:20)
// End (2023-10-19 23:20)

#include <iostream>

using namespace std;

int N;
string VideoArr[64];	// const char
string Comp;

int Index = 0;

bool Check(int Index)
{
	for (int i = Index; i < 4; i++)
	{
		if (VideoArr[Index][i])
		{

		}
	}
}

void Quad(int Start, int End)
{
	Comp += '(';

	for (int i = Start; i < End / 2; i++)
	{
		if (Check(i))
		{

		}
		else
		{
			//Quad();
		}
	}

	Comp += ')';
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> VideoArr[i];
	}

	Quad(0, N);

	return 0;
}