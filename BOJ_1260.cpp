// Start (2023-10-10 18:57)
// End	 (2023-10-10 19:57) - 실패

#include <iostream>
#include <vector>

const int Min = 1;
const int MaxN = 1001;
const int MaxM = 10001;

int N, M, V;

bool Ms[MaxN][MaxN];
bool Visited[MaxN];

std::vector<int> DFSArray;
std::vector<int> BFSArray;

void DFS(int V)
{
	DFSArray.push_back(V);
	Visited[V] = true;

	for (int i = 1; i <= N; i++)
	{
		if ((Ms[V][i]) && !(Visited[i]))
		{
			Visited[i] = true;
			DFS(i);
		}
	}
}

void BFS(int V)
{
	Visited[V] = true;

	for (int i = 1; i <= N; i++)
	{
		if ((Ms[V][i]) && !(Visited[i]))
		{
			Visited[i] = true;
			BFSArray.push_back(i);
		}
	}
}

int main()
{
	//DFS : Stack
	//BFS : Queue
	std::cin >> N >> M >> V;

	if ((N < Min || N >= MaxN) || (M < Min || M >= MaxM))	// Exeption
		return 0;

	for (int i = 1; i <= M; i++)
	{
		int Start, End;
		std::cin >> Start >> End;

		Ms[Start][End] = true;
		Ms[End][Start] = true;
	}

	// DFS
	DFS(V);

	// Reset
	for (int i = 0; i < N; i++)
		Visited[i] = false;

	// BFS
	BFSArray.push_back(V);
	for (int i = 0; i < N; i++)
		BFS(BFSArray[i]);	// 이쪽 부분이 문제


	//	Print

	for (auto& v : DFSArray)
		std::cout << v << " ";

	std::cout << "\n";

	for (auto& v : BFSArray)
		std::cout << v << " ";

	return 0;
}