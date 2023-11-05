// Start (2023-11-03 22:46)
// End (2023-11-03 23:46)

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

typedef unsigned int UINT;

using namespace std;
// 앞 뒤 접근이 가능 + 다른 원소에도 접근이 가능(list) / 대소문자 구분이 X -> Upper or Lower를 써야할지도?
// 있으면 1, 없으면 5

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

		if (cityL.empty())	// 맨 첫번째
		{
			cityL.push_back(city);
			answer += 5;

			continue;
		}

		for (auto iter = cityL.begin(); iter != cityL.end(); iter++)	// 이후 확인 조건
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
		else  // 같은 게 없을 때
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