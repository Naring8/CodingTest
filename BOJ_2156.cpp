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

	// i == 3�� ��, 0��°�� ����ϱ� ���� ���Ƿ� ����
	DP[0] = Arr[0];
	DP[1] = Arr[1];
	DP[2] = Arr[1] + Arr[2];

	// 3�� ���� ���� �� ����.
	// 1. ������ ���� �������� 3��° �տ� ���� ���ð�, 2��° �տ� ���� �ǳʶٰ� 1��° �տ� �� + �������� 
	// 2. ������ ���� �������� 2��° �տ� ���� ���ð� + ������ ��
	// 3. ������ ���� ������ �ʰ�, 1��° �տ� ���� �ִ�
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

// 1. ���� ������ ����� �ϰ� ����
// 2. ��� �ְ� ���� ��� (1. �տ������� 2. �ڿ�������)
// ���ӵ��� �ʰԴ� ��� �Ǻ��ϴ°� => pair�� �� �� ���������� �Ǻ�? �̷��� �ʹ� ����������
// ��Ģ�� �����ٵ�..

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