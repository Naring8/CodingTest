// Start (2023-10-30 21:55)
// End (2023-10-30 22:35)

/*#include <iostream>
#include <map>

using namespace std;

map<int, int> prices;	// {count, price}

int GetMaxPrice(const int MaxCount)
{
	int MaxPrice = prices[MaxCount];

	if (!MaxCount)
		return MaxPrice;

	for (int i = 1; i < MaxCount; i++)
	{
		int div = MaxCount / i;
		int remain = MaxCount % i;

		int remainPrice = GetMaxPrice(remain);

		if (prices[i] * div + remainPrice > MaxPrice)
			MaxPrice = prices[i] * div + remainPrice;
	}

	return MaxPrice;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	prices[0] = 0;
	for (int i = 1; i <= N; i++)	// input
	{
		int price;
		cin >> price;
		prices[i] = price;
	}

	cout << GetMaxPrice(N);

	return 0;
}*/

//===============================================================================================

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> prices;	// {number, price}
int MaxPrices[1001];

int GetMaxPrice(const int MaxCount)
{
	int MaxPrice = prices[MaxCount];

	if (!MaxCount)
		return MaxPrice;

	for (int i = 1; i <= MaxCount; i++)
		for (int j = 1; j <= i; j++)
			MaxPrices[i] = max(MaxPrices[i], MaxPrices[i - j] + prices[j]);

	return MaxPrices[MaxCount];
}

int main()
{
	int N;
	cin >> N;

	prices[0] = 0;
	for (int i = 1; i <= N; i++)	// input
	{
		int price;
		cin >> price;
		prices[i] = price;
	}

	cout << GetMaxPrice(N);

	return 0;
}