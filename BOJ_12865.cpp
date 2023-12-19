// 18:47 ~ 19:25
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> obj[101];
int arr[101][100001];

int main() 
{ 
	cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> obj[i].first >> obj[i].second;

	for (int i = 1; i <= n; i++)
	{ 
		for (int j = 0; j <= k; j++)
		{ 
			arr[i][j] = arr[i - 1][j];

			if (obj[i].first <= j)
				arr[i][j] = max(obj[i].second + arr[i - 1][j - obj[i].first], arr[i][j]);
		} 
	}

	cout << arr[n][k];

	return 0; 
}

/*int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K; cin >> N >> K;

	int Values[101] = {};
	vector<pair<int, int>> inputs;

	int total = 0;
	while (N--)
	{
		int W, V; cin >> W >> V;
		inputs.push_back({ W, V });
		Values[W] = std::max(Values[W], V);
	}

	for (int i = 0; i < inputs.size() - 1; i++)
	{
		int sumW = inputs[i].first;
		int sumV = inputs[i].second;

		for (int j = i + 1; j < inputs.size(); j++)
		{
			sumW += inputs[j].first;
			if (sumW > K)
				break;

			sumV += inputs[j].second;
			Values[sumW] = sumV;
		}
	}

	for (int i = 1; i <= K; i++)
		total = std::max(total, Values[i]);

	cout << total;

	return 0;
}*/