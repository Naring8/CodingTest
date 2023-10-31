// Start (2023-10-31 18:16)
// End (2023-10-31 18:46)

#include <iostream>
#include <vector>

using namespace std;

const int Max = 101;
int sum[Max][Max];
vector<int> Sums;

int C;
int N;

void Clear()
{
	for (int i = 0; i < Max; i++)
		for (int j = 0; j < Max; j++)
			sum[i][j] = 0;
}

void FindMax()
{
	int Max = 0;

	for (int i = 0; i < N; i++)
		if (sum[N - 1][i] > Max)
			Max = sum[N - 1][i];

	Sums.push_back(Max);
}

void Input()
{
	cin >> N;

	// Default (0, 0)
	cin >> sum[0][0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int temp;
			cin >> temp;

			if (j == 0)
				sum[i][j] = sum[i - 1][j] + temp;
			else if (j == i)
				sum[i][j] = sum[i - 1][j - 1] + temp;
			else
				sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + temp;
		}
	}

	FindMax();

	Clear();
}

int main()
{
	cin >> C;

	for (int i = 0; i < C; i++)
		Input();

	for (auto& i : Sums)
		cout << i << "\n";

	return 0;
}