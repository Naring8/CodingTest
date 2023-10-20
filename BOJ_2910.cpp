// Start (2023-10-20 19:20)
// End	 (2023-10-20 20:20)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> order;

void Print(const vector<int>& Vec)	// Print Vector	Func
{
	for (int i = 0; i < Vec.size(); i++)
		cout << Vec[i] <<" ";
	cout << "\n";
}

void SortMapByValue(const map<int, int>& Map, vector<pair<int, int>>& destVec)	// map�� ��� ���� vector�� ��ȯ �� ���� 
{
	vector<pair<int, int>> vec(Map.begin(), Map.end());

	sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b)
		{
			if (a.second == b.second)	// �� ���� ���ٸ�
				return order[a.first] < order[b.first];	// order ���� ���� �������

			return a.second > b.second;	// �� ���� ���� �������
		}
	);

	destVec = vec;
}

int main()
{
	int N, C;
	cin >> N >> C;

	vector<int> lNum;
	vector<pair<int, int>> lNumCpy;	// ���� �� �� ���� ���� (map)
	map<int, int> lNumMap;	// first : Num  second : count
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num <= C)
		{
			lNumMap[num]++;
			if (order.find(num) == order.end())	// ���� �� ���� ������ ���� ���ڶ��
				order.insert({ num, i });
		}
	}

	SortMapByValue(lNumMap, lNumCpy);

	vector<int> ans;
	for (int i = 0; i < lNumCpy.size(); i++)
	{
		for (int j = 0; j < lNumCpy[i].second; j++)
			ans.push_back(lNumCpy[i].first);	// ������ ����� vector�� ���� Num�� push_back
	}

	Print(ans);

	return 0;
}