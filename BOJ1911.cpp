// Start (2023-10-09 15:30)
// End (2023-10-09 16:30) - ½ÇÆÐ

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N; // ¹°¿õµ¢ÀÌ °¹¼ö
	int L; // ³ÎºþÁöÀÇ ±æÀÌ

	int MinCountL = 0;

	std::cin >> N >> L;

	std::vector<std::pair<int, int>> TempVector;

	// Sorting
	for (int i = 0; i < N; i++)
	{
		int StartIndex = 0;
		int EndIndex = 0;

		std::cin >> StartIndex >> EndIndex;

		TempVector.push_back({ StartIndex, EndIndex });
	}

	std::sort(TempVector.begin(), TempVector.end());

	int curIndex = 0;

	for (int i = 0; i < N; ++i)
	{
		if (curIndex >= TempVector[i].first && curIndex < TempVector[i].second)
		{
			int quotient = (TempVector[i].second - curIndex) / L;	// ÇÑ ¼¼Æ® ´ç ÇÊ¿ä ³ÎºþÁö °¹¼ö
			int remainder = (TempVector[i].second - curIndex) % L;	// ¿õµ¢ÀÌ¸¦ ÀüºÎ ±ò°í ³²Àº ±æ

			curIndex += quotient * L;
			MinCountL += quotient;

			if (remainder != 0)
			{
				MinCountL++;
				curIndex += L;
			}
		}
		else if (curIndex < TempVector[i].first)
		{
			curIndex = TempVector[i].first;
			--i;
		}
	}

	std::cout << MinCountL << std::endl;

	return 0;
}