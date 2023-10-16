// Start (2023-10-13 19:19)
// End	 (2023-10-13 19:39) - Æ÷±â

#include <iostream>
#include <vector>

int KnightMove()
{
	// Knight Move 1 : X + 1 Y + 2
	// Knight Move 2 : X + 1 Y - 2
	// Knight Move 3 : X - 1 Y + 2
	// Knight Move 4 : X - 1 Y - 2

	// Knight Move 5 : X + 2 Y + 1
	// Knight Move 6 : X + 2 Y - 1
	// Knight Move 7 : X - 2 Y + 1
	// Knight Move 8 : X - 2 Y - 1

}

int main()
{
	int Num;
	std::cin >> Num;

	std::vector<int> MinMoves;
	for (int i = 0; i < Num; i++)
	{
		int I;
		std::cin >> I;

		int curCoordX, curCoordY;
		std::cin >> curCoordX >> curCoordY;

		int moveCoordX, moveCoordY;
		std::cin >> moveCoordX >> moveCoordY;
	}

	return 0;
}