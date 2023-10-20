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

void SortMapByValue(const map<int, int>& Map, vector<pair<int, int>>& destVec)	// map에 담긴 수를 vector로 변환 후 정렬 
{
	vector<pair<int, int>> vec(Map.begin(), Map.end());

	sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b)
		{
			if (a.second == b.second)	// 빈도 수가 같다면
				return order[a.first] < order[b.first];	// order 값이 작은 순서대로

			return a.second > b.second;	// 빈도 수가 많은 순서대로
		}
	);

	destVec = vec;
}

int main()
{
	int N, C;
	cin >> N >> C;

	vector<int> lNum;
	vector<pair<int, int>> lNumCpy;	// 많은 빈도 수 별로 정렬 (map)
	map<int, int> lNumMap;	// first : Num  second : count
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num <= C)
		{
			lNumMap[num]++;
			if (order.find(num) == order.end())	// 아직 한 번도 나오지 않은 숫자라면
				order.insert({ num, i });
		}
	}

	SortMapByValue(lNumMap, lNumCpy);

	vector<int> ans;
	for (int i = 0; i < lNumCpy.size(); i++)
	{
		for (int j = 0; j < lNumCpy[i].second; j++)
			ans.push_back(lNumCpy[i].first);	// 정답을 출력할 vector를 만들어서 Num만 push_back
	}

	Print(ans);

	return 0;
}