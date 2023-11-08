// Start (2023-11-08 21:21)

#include <iostream>
#include <vector>

using namespace std;

const int Max = 10;

int main()
{
	int N; cin >> N;

	// Height, Taller
	vector<pair<int, int>> players;
	vector<int> tallers;
	int playerSeq[Max];

	for (int i = 0; i < N; i++)
	{
		int taller; cin >> taller;
		players.push_back({ i + 1, taller });
		tallers.push_back(taller);
		playerSeq[i] = N;
	}

	for (int i = 0; i < N; i++)
	{
		if (playerSeq[players[i].second] < players[i].first)
		{
			players[i].second++;
			i--;
		}
		else
		{
			int count = tallers[i];
			for (int j = 0; j < players[i].second; j++)
				if (playerSeq[j] > players[i].first)
					count--;

			playerSeq[players[i].second + count] = players[i].first;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << playerSeq[i] << " ";
	}
}