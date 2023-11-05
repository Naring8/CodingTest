// Start (2023-11-03 22:46)
// End (2023-11-03 23:46)

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

typedef unsigned int UINT;

using namespace std;
// �� �� ������ ���� + �ٸ� ���ҿ��� ������ ����(list) / ��ҹ��� ������ X -> Upper or Lower�� ���������?
// ������ 1, ������ 5

int solution(int cacheSize, vector<string> cities)
{
	int answer = 0;

	list<string> cityL;

	if (cacheSize == 0)
		return cities.size() * 5;

	for (auto& c : cities)
	{
		string city = c;
		transform(city.begin(), city.end(), city.begin(), ::toupper);
		bool findData = false;

		if (cityL.empty())	// �� ù��°
		{
			cityL.push_back(city);
			answer += 5;

			continue;
		}

		for (auto iter = cityL.begin(); iter != cityL.end(); iter++)	// ���� Ȯ�� ����
		{
			if (*iter == city)
			{
				cityL.erase(iter);
				cityL.push_back(city);

				answer += 1;
				findData = true;
				break;
			}
		}

		if (findData)
			continue;
		else  // ���� �� ���� ��
		{
			cityL.push_back(city);
			answer += 5;
			if (cityL.size() > cacheSize)
				cityL.pop_front();
		}
	}

	return answer;
}


int main()
{
	cout << solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }) << "\n";
	cout << solution(3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" }) << "\n";
	cout << solution(2, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" }) << "\n";
	cout << solution(5, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" }) << "\n";
	cout << solution(2, { "Jeju", "Pangyo", "NewYork", "newyork" }) << "\n";
	cout << solution(0, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }) << "\n";

}