// Start (2023-11-21 22:50)
// Start (2023-11-21 24:11)

#include <iostream>
#include <queue>

using namespace std;

typedef unsigned int uint;

int Array[20][20];

struct Dice
{
	uint UP = 0;
	uint DOWN = 0;
	uint FRONT = 0;
	uint BACK = 0;
	uint LEFT = 0;
	uint RIGHT = 0;
};

enum Moves
{
	IDLE,	// 0
	EAST,	// 1
	WEST,	// 2
	NORTH,	// 3
	SOUTH	// 4
};

int main()
{
	// N, M, x, y, K

	// Set Array(Map)
	int N, M, x, y, K; cin >> N >> M >> x >> y >> K;

	int curX = x;
	int curY = y;

	Dice dice;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp; cin >> temp;
			Array[i][j] = temp;
		}
	}

	// Init
	dice.DOWN = Array[curX][curY];
	for (int i = 0; i < K; i++)
	{
		int tmpMove; cin >> tmpMove;

		switch ((Moves)tmpMove)
		{
		case IDLE:
			break;
		case EAST:
		{
			if (curY + 1 == M)
				break;
			else
				curY += 1;

			int temp = dice.RIGHT;
			dice.RIGHT = dice.UP;
			dice.UP = dice.LEFT;
			dice.LEFT = dice.DOWN;
			dice.DOWN = temp;

			if (Array[curX][curY] == 0)
				Array[curX][curY] = dice.DOWN;
			else
			{
				dice.DOWN = Array[curX][curY];
				Array[curX][curY] = 0;
			}

			cout << dice.UP << endl;
		}
			break;
		case WEST:
		{
			if (curY - 1 < 0)
				break;
			else
				curY -= 1;

			int temp = dice.LEFT;
			dice.LEFT = dice.UP;
			dice.UP = dice.RIGHT;
			dice.RIGHT = dice.DOWN;
			dice.DOWN = temp;

			if (Array[curX][curY] == 0)
				Array[curX][curY] = dice.DOWN;
			else
			{
				dice.DOWN = Array[curX][curY];
				Array[curX][curY] = 0;
			}

			cout << dice.UP << endl;
		}
			break;
		case NORTH:
		{
			if (curX - 1 < 0)
				break;
			else
				curX -= 1;

			int temp = dice.UP;
			dice.UP = dice.FRONT;
			dice.FRONT = dice.DOWN;
			dice.DOWN = dice.BACK;
			dice.BACK = temp;

			if (Array[curX][curY] == 0)
				Array[curX][curY] = dice.DOWN;
			else
			{
				dice.DOWN = Array[curX][curY];
				Array[curX][curY] = 0;
			}

			cout << dice.UP << endl;
		}
			break;
		case SOUTH:
		{
			if (curX + 1 == N)
				break;
			else
				curX += 1;

			int temp = dice.UP;
			dice.UP = dice.BACK;
			dice.BACK = dice.DOWN;
			dice.DOWN = dice.FRONT;
			dice.FRONT = temp;

			if (Array[curX][curY] == 0)
				Array[curX][curY] = dice.DOWN;
			else
			{
				dice.DOWN = Array[curX][curY];
				Array[curX][curY] = 0;
			}

			cout << dice.UP << endl;
		}
			break;
		default:
			break;
		}
	}
}