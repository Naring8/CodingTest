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
	���ʿ��� ���� ���̵� �������� �ʾ���
	Map�� �� ���� �ٲ� ��¥�� Check�Ѵ� *
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
			Map[nx][ny] = Map[cur.first][cur.second] + 1;	// days�� check�� �뵵

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

	// ó������ �丶�並 �Է¹޾��� �� days�� 1�̹Ƿ�
	// �Ϸ縦 �������
	return --days;
}

int main()
{
	// M : ����  N : ����
	cin >> M >> N;

	// 1 : ����, 0 : ���� ����, -1 : �丶��X
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