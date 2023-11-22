// Start (2023-11-22 19:50)
// End (2023-11-22 21:20)
#include <iostream>
#include <string>

using namespace std;

typedef unsigned int uint;

int total_min = 48;
int total_sec = 00;

enum Teams
{
	IDLE,
	TEAM_A,
	TEAM_B
};

int* CalcTime(int goal_min, int goal_sec, int end_min, int end_sec)
{
	int times[2];

	end_min -= goal_min;

	if ((end_sec - goal_sec) < 0)
	{
		end_min--;
		end_sec = 60 - goal_sec;
	}
	else
		end_sec -= goal_sec;

	times[0] = end_min;
	times[1] = end_sec;

	return times;
}

int* DivTime(string time)
{
	int times[2];
	int min = 0;
	for (uint i = 0; i < time.size(); i++)
	{
		if (time[i] == ':')
		{
			times[0] = min;
			min = 0;
			continue;
		}
		int time_10 = time[i] - '0';
		int time_1 = time[++i] - '0';

		min = time_10 * 10 + time_1;
	}
	times[1] = min;

	return times;
}

string ConvTime(int min, int sec)
{
	string time = "";

	if (min < 10)
		time += "0" + to_string(min);
	else
		time += to_string(min);

	time += ":";

	if(sec < 10)
		time += "0" + to_string(sec);
	else
		time += to_string(sec);

	return time;
}

int main()
{
	int N; cin >> N;	// 홀수 : 누군가 이긴 상태 / 짝수 : 비긴 상태

	uint teamA = 0;
	uint teamB = 0;

	int timeA[2] = { 0, 0 };
	int timeB[2] = { 0, 0 };

	int startTime[2] = { 0, 0 };
	int endTime[2] = { 0, 0 };

	int* times;

	string winTimeA = "";
	string winTimeB = "";

	for (int i = 0; i < N; i++)
	{
		int team; cin >> team;
		string time; cin >> time;

		int* times = DivTime(time);

		switch ((Teams) team)
		{
		case TEAM_A:
			teamA++;
			break;
		case TEAM_B:
			teamB++;
			break;
		}

		if (teamA != teamB && (startTime[0] == 0 && startTime[1] == 0))
		{
			startTime[0] = times[0];
			startTime[1] = times[1];
		}
		else if(teamA == teamB)
		{
			endTime[0] = times[0];
			endTime[1] = times[1];

			times = CalcTime(startTime[0], startTime[1], endTime[0], endTime[1]);

			switch ((Teams)team)
			{
			case TEAM_A:	// B가 이기고 있었음
			{
				timeB[0] += times[0];
				timeB[1] += times[1];
			}
				break;
			case TEAM_B:	// A가 이기고 있었음
			{
				timeA[0] += times[0];
				timeA[1] += times[1];
			}
				break;
			}
			startTime[0] = 0;
			startTime[1] = 0;
		}
	}
	times = CalcTime(startTime[0], startTime[1], total_min, total_sec);
	if (teamA > teamB)
	{
		timeA[0] += times[0];
		timeA[1] += times[1];
	}
	else if(teamB > teamA)
	{
		timeB[0] += times[0];
		timeB[1] += times[1];
	}

	winTimeA = ConvTime(timeA[0], timeA[1]);
	winTimeB = ConvTime(timeB[0], timeB[1]);

	cout << winTimeA << "\n";
	cout << winTimeB;

	return 0;
}