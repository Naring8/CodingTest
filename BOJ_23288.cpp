// 20:40 ~ 24:00
#include <iostream>
#include <queue>

using namespace std;
typedef unsigned int uint;

enum Direction
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

struct Dice
{
	uint Up = 1;
	uint Down = 6;
	uint Left = 4;
	uint Right = 3;
	uint Front = 5;
	uint Back = 2;
};

struct Coord
{
	int x = 0;
	int y = 0;
};

int N, M, K;
int Map[20][20];
bool Visited[20][20] = { false };
queue<Coord> mapQ;

void MoveByDirection(Dice& dice, Direction& direct, Coord& curCoord)
{
	switch (direct)
	{
	case UP:
	{
		uint temp = dice.Up;
		dice.Up = dice.Front;
		dice.Front = dice.Down;
		dice.Down = dice.Back;
		dice.Back = temp;

		curCoord.y++;
	}
	break;
	case LEFT:
	{
		uint temp = dice.Up;
		dice.Up = dice.Right;
		dice.Right = dice.Down;
		dice.Down = dice.Left;
		dice.Left = temp;

		curCoord.x--;
	}
	break;
	case DOWN:
	{
		uint temp = dice.Up;
		dice.Up = dice.Back;
		dice.Back = dice.Down;
		dice.Down = dice.Front;
		dice.Front = temp;

		curCoord.x--;
	}
	break;
	case RIGHT:
	{
		uint temp = dice.Up;
		dice.Up = dice.Left;
		dice.Left = dice.Down;
		dice.Down = dice.Right;
		dice.Right = temp;

		curCoord.x++;
	}
	break;
	}
}

int CheckCoordByValue(const Coord coord, const int value)
{
	int dirVal = 0;

	// Up
	if (Map[coord.y - 1][coord.x] == value && !Visited[coord.y - 1][coord.x])
	{
		dirVal++;
		mapQ.push(Coord{ coord.x, coord.y - 1 });
	}

	// Down
	if (Map[coord.y + 1][coord.x] == value && !Visited[coord.y + 1][coord.x])
	{
		dirVal++;
		mapQ.push(Coord{ coord.x, coord.y + 1 });
	}

	// Left
	if (Map[coord.y][coord.x - 1] == value && !Visited[coord.y][coord.x - 1])
	{
		dirVal++;
		mapQ.push(Coord{ coord.x - 1, coord.y });
	}

	// Right
	if (Map[coord.y][coord.x + 1] == value && !Visited[coord.y][coord.x + 1])
	{
		dirVal++;
		mapQ.push(Coord{ coord.x + 1, coord.y });
	}

	return dirVal;
}

int BFSCheck(Coord coord)
{
	int total = 1;

	mapQ.push(coord);
	int value = Map[coord.y][coord.x];
	while (!mapQ.empty())
	{
		Visited[mapQ.front().y][mapQ.front().x] = true;
		total += CheckCoordByValue(mapQ.front(), value) * value;

		mapQ.pop();
	}

	return total;
}

void InitVisited()
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			Visited[i][j] = false;
}

int main()
{
	cin >> N >> M;
	cin >> K;	// Move Count

	// Input ( (0, 0) ~ (N - 1, M - 1) )
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];

	Dice dice;
	Direction dDirection = Direction::RIGHT;
	Coord curCoord;

	int total = 0;

	do
	{
		switch (dDirection)
		{
		case UP:
		{
			if (curCoord.y - 1 < 0)
				dDirection = DOWN;
		}
		break;
		case LEFT:
		{
			if (curCoord.x - 1 < 0)
				dDirection = RIGHT;
		}
		break;
		case DOWN:
		{
			if (curCoord.y + 1 >= N)
				dDirection = UP;
		}
		break;
		case RIGHT:
		{
			if (curCoord.x + 1 >= M)
				dDirection = LEFT;
		}
		break;
		}
		MoveByDirection(dice, dDirection, curCoord);
		total += BFSCheck(curCoord);

		if ((int)dice.Down > Map[curCoord.y][curCoord.x])
			dDirection = (Direction)((int)dDirection + 1);	// 시계 방향
		else if ((int)dice.Down < Map[curCoord.y][curCoord.x])
			dDirection = (Direction)((int)dDirection - 1);	// 반시계 방향

		InitVisited();

	} while (--K);

	cout << total;

	return 0;
}