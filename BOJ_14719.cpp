// 21:08
// 22:10
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int H, W; cin >> H >> W;
	int rains = 0;

	vector<int> blocks(W);

	for (int i = 0; i < W; i++)
		cin >> blocks[i];

	int base = blocks[0];
	int last = blocks[0];

	vector<int> stuckBlocks;
	for (int i = 1; i < W; i++)
	{
		if (blocks[i] >= base || i == W - 1)
		{
			if (i == W - 1)
				if (last < blocks[i])
					last = blocks[i];

			int minBlock = min(base, last);
			for (auto& block : stuckBlocks)
				rains += minBlock - block;

			base = blocks[i];
			last = 0;
			stuckBlocks.clear();
		}
		else
		{
			stuckBlocks.push_back(blocks[i]);
			if (last < blocks[i])
				last = blocks[i];
		}

		/*if(base <= blocks[i] || i == W - 1)
		{
			if (!bStack)
			{
				base = blocks[i];
				continue;
			}

			bStack = false;
			int minBase = min(base, blocks[i]);

			for (int& block : stuckBlocks)
				rains += minBase - block;

			stuckBlocks.clear();
			base = blocks[i];
		}

		else if (base > blocks[i])
		{
			bStack = true;
			stuckBlocks.push_back(blocks[i]);
		}*/
	}

	cout << rains;

	return 0;
}