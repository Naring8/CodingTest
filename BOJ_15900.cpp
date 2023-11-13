// Start (2023-11-13 17:55)
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int UINT;

vector<int> nodes[500001];
vector<bool> visitied;
int total = 0;

void DFS(int start, int count)
{
	// leaf 노드 판별
	// 자식이 하나라면? + 시작이 1이 아니라면
	if (nodes[start].size() == 1 && start != 1)
	{
		total += count;
		return;
	}

	// 내려가기 + 중복 제거
	for (UINT i = 0; i < nodes[start].size(); i++)
	{
		if (!visitied[nodes[start][i]])
		{
			visitied[nodes[start][i]] = true;
			DFS(nodes[start][i], count + 1);
			visitied[nodes[start][i]] = false;
		}
	}
}

int main()
{
	int N; cin >> N;

	// Init
	visitied.push_back(false); // 0 : 사용하지 않는 Index
	visitied.push_back(true); // 1 : 무조건 시작 Index
	for (int i = 0; i < N - 1; i++)
	{
		int a, b; cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);

		visitied.push_back(false);
	}
	DFS(1, 0);
	
	// 총 올라간 횟수가 (짝수면 = NO, 홀수면 = Yes)
	(total % 2) ? cout << "Yes" : cout << "No";

	return 0;
}