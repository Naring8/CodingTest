// Start (2023-11-15 20:31)
// End (2023-11-15 21:10)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������ ���ӵǾ�� �ϹǷ�
// �־��� �迭�� M��ŭ �ɰ��� ���� ����� ���� Ž������ ���ϰ� { 15, 13, 17 }
// �� �߿��� ���� ū ���� return �ϸ� �ȴ�.
// 
// ���� Ž�� : �߾��� ���� ������ ������ ���ϰ�
// ���� ���� ���ϴ� ������ ū ��, ���� �� Ȯ�� ��
// ���ǿ� ���� �ٽ� �ݺ��ϴ� Ž�� ���

int main()
{
	int N, M; cin >> N >> M;
	vector<int> mins;

	int max_video = 0; // 1���� �� ���� ��(�ִ�)
	int min_video = 0; // N���� �� ���� ��(�ּڰ�)
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
		int count = 0;	// ��緹�� ����
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