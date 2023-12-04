// 19:55 ~ 20:25
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[1000001] = { 0 };

int find(int k)
{
	if (k == parent[k])
		return k;

	return parent[k] = find(parent[k]);
}

void union_find(int u, int v)
{
	int x = find(u);
	int y = find(v);
	
	if (x != y)
		parent[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;

		if (a == 1)	// Yes or No
		{
			if (find(b) == find(c))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		else		// set
			union_find(b, c);
	}

	return 0;
}