// Start (2023-11-23 00:35)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

int main()
{
	uint N; cin >> N;

	map<int, vector<int>> assigns;

	uint lastDay = 1;
	uint totalScore = 0;

	for (uint i = 0; i < N; i++)
	{
		int day, score; cin >> day >> score;

		assigns[day].push_back(score);

		if (day > lastDay)
			lastDay = day;
	}

	// map에 있는 vector를 점수가 작은 순서대로 정렬 (뒤에 걸 빼기 위해)
	for (auto& day : assigns)
		std::sort(day.second.begin(), day.second.end());
	
	for (uint i = lastDay; i >= 1; i--)
	{
		uint repDay = 0;
		uint maxScore = 0;

		for (uint j = i; j <= lastDay; j++)
		{
			if (!assigns[j].empty())
			{
				if (assigns[j].back() > maxScore)
				{
					repDay = j;
					maxScore = assigns[j].back();
				}
			}
		}

		if (maxScore != 0)
		{
			totalScore += maxScore;
			assigns[repDay].pop_back();
		}
	}
	
	cout << totalScore;

	return 0;
}