// ���� (2023-10-08  17:00)
// ���� (2023-10-08  18:00) - ����

#include <iostream>
#include <vector>

struct RGB
{
	int R = 0;
	int G = 0;
	int B = 0;

	int Sum() { return R + G + B; }
};

int main()
{
	int N;

	std::cin >> N;
	if (N < 2 || N > 1000)
		return 0;

	std::vector<RGB> ColorCosts;
	int MinCost = 0;

	for (int i = 0; i < N; i++)
	{
		int ValueR, ValueG, ValueB;
		std::cin >> ValueR >> ValueG >> ValueB;

		{
			RGB temp;
			temp.R = ValueR;
			temp.G = ValueG;
			temp.B = ValueB;

			ColorCosts.push_back(temp);

			MinCost += temp.Sum();
		}
	}

	{
		int Cost = 0;

		// ù��°�� R
		Cost += ColorCosts[0].R;


		// ù��°�� G
		Cost += ColorCosts[0].G;


		// ù��°�� B
		Cost += ColorCosts[0].B;

	}
	


	return 0;
}