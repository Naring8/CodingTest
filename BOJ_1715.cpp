// 18:31 ~ 
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N; cin >> N;
	priority_queue<int, vector<int>, greater<>> cards;
	//vector<int> cards;

	int cmpCount = 0;

	for (int i = 0; i < N; i++)
	{
		int cSize; cin >> cSize;
		cards.push(cSize);
		//cards.push_back(cSize);	// vector
	}

	while (cards.size() > 1)
	{
		int sum = cards.top(); cards.pop();
		sum += cards.top(); cards.pop();

		cards.push(sum);
		cmpCount += sum;

		// vector
		/*sort(cards.begin(), cards.end(), greater<>());
		int sum = cards[cards.size() - 1] + cards[cards.size() - 2];
		cards.pop_back(); cards.pop_back();

		cmpCount += sum;
		cards.push_back(sum);*/
	}

	cout << cmpCount;

	return 0;
}