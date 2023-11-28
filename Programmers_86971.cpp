// Start (2023-11-28 22:16)
// End (2023-11-28 23:16)

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MaxN = 101;

int countNode = 0;
vector<int> tree[MaxN];

void BFS(int a, int b)
{
    queue<int> bfs;
    bool visited[MaxN] = { false };

    bfs.push(a);
    visited[a] = true; visited[b] = true;

    while (!bfs.empty())
    {
        int front = bfs.front();
        bfs.pop();

        for (int i = 0; i < tree[front].size(); i++)
        {
            int next = tree[front][i];

            if (visited[next]) 
                continue;

            countNode++;
            bfs.push(next);
            visited[next] = true;
        }
    }
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = MaxN;

    for (auto& w : wires)
    {
        tree[w[0]].push_back(w[1]);
        tree[w[1]].push_back(w[0]);
    }

    for (auto& wire : wires)
    {
        countNode = 1;

        BFS(wire[0], wire[1]);
        answer = min(answer, abs(2 * countNode - n));
    }
    
    return answer;
}

int main()
{
    cout << solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}} );

    return 0;
}