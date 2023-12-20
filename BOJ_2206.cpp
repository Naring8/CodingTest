// 17:38 ~ 18:50
#include <iostream>
#include <queue>

using namespace std;

struct Coord
{
	int X; int Y;
};

queue<pair<pair<int, int>, bool>> way;

int N, M;

bool Visited[1001][1001];
bool Map[1001][1001];
int Path[1001][1001];

// BFS ?
void BFS()
{
	while (!way.empty())
	{
		const pair<int, int> temp = way.front().first;

		bool canBreak = way.front().second;
		int count = Path[temp.first][temp.second];
		Visited[temp.first][temp.second] = true;

		way.pop();

		// Coord (X, Y)
		Coord    Up = { temp.second, temp.first - 1 };
		Coord  Down = { temp.second, temp.first + 1 };
		Coord  Left = { temp.second - 1, temp.first };
		Coord Right = { temp.second + 1, temp.first };

		// Up (범위 + 방문 확인)
		if (Up.Y > 0 && !Visited[Up.Y][Up.X])
		{
			// (현재 있는 곳이 0이면 그냥 Path 추가, 1이면 canBreak를 확인 후 Path 추가)
			if (Map[Up.Y][Up.X])
			{
				if (canBreak)
				{
					way.push({ { Up.Y, Up.X }, !canBreak });
					Path[Up.Y][Up.X] = count + 1;
				}
			}
			else
			{
				way.push({ { Up.Y, Up.X }, canBreak });
				Path[Up.Y][Up.X] = count + 1;
			}
		}

		// Down
		if (Down.Y <= N && !Visited[Down.Y][Down.X])
		{
			// (현재 있는 곳이 0이면 그냥 Path 추가, 1이면 canBreak를 확인 후 Path 추가)
			if (Map[Down.Y][Down.X])
			{
				if (canBreak)
				{
					way.push({ { Down.Y, Down.X }, !canBreak });
					Path[Down.Y][Down.X] = count + 1;
				}
			}
			else
			{
				way.push({ { Down.Y, Down.X }, canBreak });
				Path[Down.Y][Down.X] = count + 1;
			}
		}

		// Left
		if (Left.X > 0 && !Visited[Left.Y][Left.X])
		{
			// (현재 있는 곳이 0이면 그냥 Path 추가, 1이면 canBreak를 확인 후 Path 추가)
			if (Map[Left.Y][Left.X])
			{
				if (canBreak)
				{
					way.push({ { Left.Y, Left.X }, !canBreak });
					Path[Left.Y][Left.X] = count + 1;
				}
			}
			else
			{
				way.push({ { Left.Y, Left.X }, canBreak });
				Path[Left.Y][Left.X] = count + 1;
			}
		}

		// Right
		if (Right.X <= M && !Visited[Right.Y][Right.X])
		{
			// (현재 있는 곳이 0이면 그냥 Path 추가, 1이면 canBreak를 확인 후 Path 추가)
			if (Map[Right.Y][Right.X])
			{
				if (canBreak)
				{
					way.push({ { Right.Y, Right.X }, !canBreak });
					Path[Right.Y][Right.X] = count + 1;
				}
			}
			else
			{
				way.push({ { Right.Y, Right.X }, canBreak });
				Path[Right.Y][Right.X] = count + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char temp; cin >> temp;
			if (temp == '1')
				Map[i][j] = true;
			else
				Map[i][j] = false;
		}
	}

	way.push({ { 1, 1 }, true });
	Path[1][1] = 1;
	BFS();

	if (Path[N][M])
		cout << Path[N][M];
	else
		cout << "-1";

	return 0;
}