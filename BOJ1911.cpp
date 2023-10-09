// Start (2023-10-09 15:30)
// End (2023-10-09 16:30) - ����

#include <iostream>
#include <vector>
#include <algorithm>

struct PoolIndex
{
	PoolIndex(int StartIndex, int EndIndex)
	{
		Start = StartIndex;
		End = EndIndex;
	}

	int Start;
	int End;
};

void SortVector(std::vector<PoolIndex> Vector, int Count)
{
	for (int i = 0; i < (Count - 1); i++)
	{
		if (Vector[i].Start > Vector[i + 1].Start)
			std::swap<PoolIndex>(Vector[i], Vector[i + 1]);
	}
}

int main()
{
	int N; // �������� ����
	int L; // �κ����� ����

	int MinCountL = 0;
	int HighestIndex = 0;

	std::cin >> N >> L;

	std::vector<PoolIndex> TempVector;
	std::vector<bool> PoolVector;
	{
		for (int i = 0; i < N; i++)
		{
			int StartIndex = 0;
			int EndIndex = 0;

			std::cin >> StartIndex >> EndIndex;

			if (HighestIndex < EndIndex) // ���� �ڿ� �ִ� �������� Index
				HighestIndex = EndIndex;

			PoolIndex Temp(StartIndex, EndIndex);

			for (int j = StartIndex; j < (EndIndex + StartIndex); j++)
				TempVector.push_back(Temp);
		}
		SortVector(TempVector, N);
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << TempVector[i].Start << std::endl;
	}

	// �տ������� �˻�
	/*for (int i = 0; i < HighestIndex; i++)
	{
		if (MaxArray[i])
		{
			std::cout << i << std::endl;
			MinCountL++;
			i += (L - 1);	
		}
	}*/

	std::cout << MinCountL << std::endl;

	// �ڿ������� �˻� 

	return 0;
}