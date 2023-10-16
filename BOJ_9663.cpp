// Start (2023-10-15 16:15)
// End (2023-10-15 17:11) - 실패

#include <iostream>

int const MAX = 15;

int N;
int QueenCount[MAX];	// MAX : Row , QueenCount[Max] : Column (N x N 이어서 순서는 상관 X)
int SolCount = 0;

bool CheckQueens(int Place)
{
	for (int i = 0; i < Place; i++)
	{
		// Not Same Row & Column / 대각선도 X
		if (QueenCount[Place] == QueenCount[i] || abs(QueenCount[Place] - QueenCount[i]) == (Place - i))
			return false;
	}

	return true;
}

void PlaceQueen(int Row)
{
	if (Row == N)
		SolCount++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			QueenCount[Row] = i;
			if (CheckQueens(Row))
				PlaceQueen(Row + 1);
		}
	}
}

int main()
{
	std::cin >> N;

	PlaceQueen(0);

	std::cout << SolCount;

	return 0;
}