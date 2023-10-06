#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NMin = 1;
const int NMax = 100000;

const int WMax = 10000;

int main()
{
	int N;
	vector<int> Weights;

	cin >> N;

	if (N < NMin || N > NMax)
		return 0;	// 예외처리

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (temp < 0 || temp > WMax)
			return 0;

		Weights.push_back(temp);
	}

	sort(Weights.begin(), Weights.end());

	int BVal = *(Weights.end() - 1);
	int MaxVal = BVal;
	for (int i = 1; i < N; i++)
	{
		int Parellal = *(Weights.end() - 1 - i) * (i + 1);
		if (MaxVal < Parellal)
			MaxVal = Parellal;
	}

	cout << MaxVal << endl;

	return 0;
}