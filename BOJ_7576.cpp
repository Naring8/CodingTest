// 18:10 ~ 19:50
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Map[1000][1000];
bool visited[1000][1000];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int M, N;
int days = 0;
queue<pair<int, int>> q;

/* 
	이쪽에서 좋은 아이디어가 생각나지 않았음
	Map에 들어간 값을 바꿔 날짜를 Check한다 *
*/
void BFS()
{
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if (days < Map[cur.first][cur.second])
			days++;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			// Direction
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			// Check
			if (visited[nx][ny] || Map[nx][ny] != 0)
				continue;

			visited[nx][ny] = true;
			Map[nx][ny] = Map[cur.first][cur.second] + 1;	// days를 check할 용도

			q.push({ nx, ny });
		}
	}
}

int Check()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Map[i][j] == 0)
				return -1;

	// 처음으로 토마토를 입력받았을 때 days가 1이므로
	// 하루를 빼줘야함
	return --days;
}

int main()
{
	// M : 가로  N : 세로
	cin >> M >> N;

	// 1 : 익음, 0 : 익지 않음, -1 : 토마토X
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp; cin >> temp;
			Map[i][j] = temp;

			if (temp == 1)
				q.push({ i, j });
		}
	}

	BFS();
	
	cout << Check();

	return 0;
}