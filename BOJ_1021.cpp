// 22:09 ~ 23:30
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, M; cin >> N >> M;

	// 양방향 순환 Queue
	deque<int> rotQ;
	queue<int> order;

	for (int i = 1; i <= N; i++)
		rotQ.push_back(i);

	for (int i = 0; i < M; i++)
	{
		int temp; cin >> temp;
		order.push(temp);
	}

	int total = 0;
	int index = 0;

	while (M--)
	{
		while (rotQ.front() != order.front())
		{
			for (int i = 0; i < rotQ.size(); i++)
			{
				if (rotQ[i] == order.front())
				{
					index = i;
					break;
				}
			}

			// 2 : 왼쪽으로 가는 게 더 빠를 때
			if (index <= rotQ.size() / 2)
			{
				int temp = rotQ.front();
				rotQ.pop_front();

				rotQ.push_back(temp);
			}
			// 3 : 오른쪽으로 가는 게 더 빠를 때
			else
			{
				int temp = rotQ.back();
				rotQ.pop_back();

				rotQ.push_front(temp);
			}
			total++;
		}

		// 1.
		rotQ.pop_front();
		order.pop();

		index = 0;
	}

	cout << total;

	return 0;
}