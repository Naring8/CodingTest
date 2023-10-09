// Start (2023-10-09 15:30)
// End (2023-10-09 16:30) - ����

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N; // �������� ����
	int L; // �κ����� ����

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
			int quotient = (TempVector[i].second - curIndex) / L;	// �� ��Ʈ �� �ʿ� �κ��� ����
			int remainder = (TempVector[i].second - curIndex) % L;	// �����̸� ���� ��� ���� ��

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