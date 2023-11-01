// Start (2023-11-01 19:30)
// End (2023-11-01 20:00)

#include <iostream>

using namespace std;

const int Max = 10001;

int n;
int Arr[Max];
int DP[Max];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> Arr[i];
	}

	// i == 3일 때, 0번째를 사용하기 위해 임의로 생성
	DP[0] = Arr[0];
	DP[1] = Arr[1];
	DP[2] = Arr[1] + Arr[2];

	// 3잔 연속 마실 수 없다.
	// 1. 마지막 잔을 기준으로 3번째 앞에 잔을 마시고, 2번째 앞에 잔을 건너뛰고 1번째 앞에 잔 + 마지막잔 
	// 2. 마지막 잔을 기준으로 2번째 앞에 잔을 마시고 + 마지막 잔
	// 3. 마지막 잔을 마시지 않고, 1번째 앞에 잔의 최댓값
	for (int i = 3; i <= n; i++)
	{
		DP[i] = max(DP[i - 3] + Arr[i - 1] + Arr[i], max(DP[i - 2] + Arr[i], DP[i - 1]));
	}

	cout << DP[n];

	return 0;
}

/*#include <iostream>
#include <vector>

using namespace std;

// 1. 넣을 때부터 계산을 하고 넣음
// 2. 모두 넣고 나서 계산 (1. 앞에서부터 2. 뒤에서부터)
// 연속되지 않게는 어떻게 판별하는가 => pair로 몇 개 연속인지를 판별? 이러면 너무 복잡해질듯
// 규칙이 있을텐데..

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> wines;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		wines.push_back({ temp, 1 });
	}
}*/