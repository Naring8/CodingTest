//// 3:59 ~ 4:20 +
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//char Map[3][3];
//string input;
//
//// 게임이 누군가의 승리로 끝났을 때 (8가지 경우의 수)
//bool CheckXWin()
//{
//	bool isXWin = false;
//
//	for (int i = 0; i < 3; i++)
//		if (Map[i][0] == 'X' && Map[i][0] == Map[i][1] && Map[i][0] == Map[i][2])
//			isXWin = true;
//	for (int j = 0; j < 3; j++)
//		if (Map[0][j] == 'X' && Map[0][j] == Map[1][j] && Map[0][j] == Map[2][j])
//			isXWin = true;
//
//	if (Map[0][0] == 'X' && Map[0][0] == Map[1][1] && Map[0][0] == Map[2][2])
//		isXWin = true;
//	if (Map[0][2] == 'X' && Map[0][2] == Map[1][1] && Map[0][2] == Map[2][0])
//		isXWin = true;
//
//	return isXWin;
//}
//
//bool CheckOWin()
//{
//	bool isOWin = false;
//
//	for (int i = 0; i < 3; i++)
//		if (Map[i][0] == 'O' && Map[i][0] == Map[i][1] && Map[i][0] == Map[i][2])
//			isOWin = true;
//	for (int j = 0; j < 3; j++)
//		if (Map[0][j] == 'O' && Map[0][j] == Map[1][j] && Map[0][j] == Map[2][j])
//			isOWin = true;
//
//	if (Map[0][0] == 'O' && Map[0][0] == Map[1][1] && Map[0][0] == Map[2][2])
//		isOWin = true;
//	if (Map[0][2] == 'O' && Map[0][2] == Map[1][1] && Map[0][2] == Map[2][0])
//		isOWin = true;
//
//	return isOWin;
//}
//
//int main()
//{
//	cin >> input;
//	while (input != "end")
//	{
//		int countO = 0;
//		int countX = 0;
//
//		bool isXWin = false;
//		bool isOWin = false;
//
//		for (int i = 0; i < 9; i++)
//		{
//			Map[i / 3][i % 3] = input[i];
//
//			if (input[i] == 'O')
//				countO++;
//			else if (input[i] == 'X')
//				countX++;
//		}
//
//		isXWin = CheckXWin();
//		isOWin = CheckOWin();
//
//		// X가 이기는 경우
//		if (isXWin && !isOWin && countX == countO + 1)
//			cout << "valid\n";
//		else if (!isXWin && isOWin && countX == countO)
//			cout << "valid\n";
//		else if (!isXWin && !isOWin && countX == 5 && countO == 4)	// 비기는 경우
//			cout << "valid\n";
//		else
//			cout << "invalid\n";
//
//		cin >> input;
//	}
//
//	return 0;
//}

// 3:59 ~ 4:20 +
#include <iostream>

using namespace std;

char Map[3][3];

int main()
{
	string temp; cin >> temp;
	while (temp != "end")
	{
		int countO = 0;
		int countX = 0;

		bool isXWin = false, isOWin = false;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Map[i][j] = temp[i * 3 + j];

				if (temp[i * 3 + j] == 'O')
					countO++;
				else if (temp[i * 3 + j] == 'X')
					countX++;
			}
		}

		// 게임이 누군가의 승리로 끝났을 때 (8가지 경우의 수)
		if (Map[0][0] == Map[0][1] && Map[0][0] == Map[0][2])
		{
			if (Map[0][0] == 'X')
				isXWin = true;
			else if (Map[0][0] == 'O')
				isOWin = true;
		}
		if (Map[0][0] == Map[1][0] && Map[0][0] == Map[2][0])
		{
			if (Map[0][0] == 'X')
				isXWin = true;
			else if (Map[0][0] == 'O')
				isOWin = true;
		}
		if (Map[0][0] == Map[1][1] && Map[0][0] == Map[2][2])
		{
			if (Map[0][0] == 'X')
				isXWin = true;
			else if (Map[0][0] == 'O')
				isOWin = true;
		}
		if (Map[0][1] == Map[1][1] && Map[0][1] == Map[2][1])
		{
			if (Map[0][1] == 'X')
				isXWin = true;
			else if (Map[0][1] == 'O')
				isOWin = true;
		}
		if (Map[0][2] == Map[1][2] && Map[0][2] == Map[2][2])
		{
			if (Map[0][2] == 'X')
				isXWin = true;
			else if (Map[0][2] == 'O')
				isOWin = true;
		}
		if (Map[0][2] == Map[1][1] && Map[0][2] == Map[2][0])
		{
			if (Map[0][2] == 'X')
				isXWin = true;
			else if (Map[0][2] == 'O')
				isOWin = true;
		}
		if (Map[1][0] == Map[1][1] && Map[1][0] == Map[1][2])
		{
			if (Map[1][0] == 'X')
				isXWin = true;
			else if (Map[1][0] == 'O')
				isOWin = true;
		}
		if (Map[2][0] == Map[2][1] && Map[2][0] == Map[2][2])
		{
			if (Map[2][0] == 'X')
				isXWin = true;
			else if (Map[2][0] == 'O')
				isOWin = true;
		}

		if (!isXWin && !isOWin && countX == 5 && countO == 4) // 승부가 안났을 때 (꽉 채움, 무승부)
			cout << "valid" << "\n";
		else if (isXWin && !isOWin && countX == countO + 1)
			cout << "valid" << "\n";
		else if (!isXWin && isOWin && countX == countO)
			cout << "valid" << "\n";
		else
			cout << "invalid" << "\n";

		cin >> temp;
	}
	return 0;
}