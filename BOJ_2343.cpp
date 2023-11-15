// Start (2023-11-15 20:31)
// End (2023-11-15 21:10)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 무조건 연속되어야 하므로
// 주어진 배열을 M만큼 쪼개서 나온 결과를 이진 탐색으로 구하고 { 15, 13, 17 }
// 그 중에서 가장 큰 값을 return 하면 된다.
// 
// 이진 탐색 : 중앙의 값을 임의의 값으로 정하고
// 정한 값이 원하는 값보다 큰 지, 작은 지 확인 후
// 조건에 맞춰 다시 반복하는 탐색 기법

int main()
{
	int N, M; cin >> N >> M;
	vector<int> mins;

	int max_video = 0; // 1개로 다 담을 때(최댓값)
	int min_video = 0; // N개로 다 담을 때(최솟값)
	for (int i = 0; i < N; i++)
	{
		int temp; cin >> temp;
		mins.push_back(temp);

		max_video += temp;
		min_video = max(min_video, temp);
	}

	int divSize = 0;
	int mid = 0;

	while (min_video <= max_video)
	{
		int count = 0;	// 블루레이 갯수
		int sum = 0;

		mid = (max_video + min_video) / 2;
		
		for (int i = 0; i < N; i++)
		{
			sum += mins[i];
			if (sum > mid)
			{
				sum = mins[i];
				count++;
			}
		}

		if (sum > 0)
			count++;

		if (count > M)
			min_video = mid + 1;
		else
			max_video = mid - 1;
	}

	cout << min_video;

}

/*int main()
{
	int N, M; cin >> N >> M;
	vector<int> mins;
	vector<int> check; // sum, index

	int total = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		mins.push_back(temp);
		total += temp;
	}

	int div = total / M;
	int sum = 0;

	for (int i = 0; i < mins.size(); i++)
	{
		if (sum + mins[i] > div)
		{
			check.push_back(sum + mins[i]);
			sum = 0;
		}
		sum += mins[i];
	}

	sort(check.begin(), check.end());

	cout << check[0];

	return 0;
}*/