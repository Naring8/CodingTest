// Start (2023-10-26 18:30)
// End (202-10-36 19:20) - 실패

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

typedef unsigned int UINT;

using namespace std;

// string으로 들어온 시간을 int로 계산 후 반환
int time_diff(string in, string out)
{
    // stoi : string to int
    // substr : 문자열 자르기 함수, substr(시작 지점, 몇 개 자를건지)
    int h1 = stoi(in.substr(0, 2));
    int m1 = stoi(in.substr(3, 2));
    int h2 = stoi(out.substr(0, 2));
    int m2 = stoi(out.substr(3, 2));

    int diff = (h2 - h1) * 60 + (m2 - m1);

    return diff;
}

// fees[0] : 기본 시간
// fees[1] : 기본 요금
// fees[2] : 단위 시간(분)
// fees[3] : 단위 요금(원)
vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, vector<string>> m;

    stringstream ss;
    for (auto& record : records)
    {
        ss.str(record);
        string time, number, status;
        ss >> time >> number >> status;

        m[number].push_back(time);
        ss.clear();
    }

    for (auto& i : m)
    {
        if (i.second.size() & 1) // 비트 연산으로 홀수개 판별
            i.second.push_back("23:59");

        vector<string> info = i.second;
        int total = 0;
        for (UINT i = 0; i < (info.size() - 1); i += 2)
            total += time_diff(info[i], info[i + 1]);

        int price = fees[1];    // 기본 요금
        if (total > fees[0])
            price += (int)ceil((total - (double)fees[0]) / fees[2]) * fees[3];
        // ceil : 올림 해주는 함수 / 실수 -> 정수
        // (double) 캐스팅이 필요한 이유 : ceil 함수가 인자로 double 형을 받기 때문

        answer.push_back(price);
    }

    return answer;
}

int main()
{

    return 0;
}

/*/// <param name="fees"> : 요금표</param>
/// <param name="records"> : 입/출차 기록</param>
/// <returns></returns>
vector<int> solution(vector<int> fees, vector<string> records)  // fees : 요금표 , records : 입/출차 기록
{
    vector<int> answer;
    map<int, int> parkingFees;

    for (auto& i : records)
    {
        string time, number, state;
    }

    return answer;
}

int main()
{
    solution({ 1, 461, 1, 10 }, { "00:00 1234 IN" });
    return 0;
}*/