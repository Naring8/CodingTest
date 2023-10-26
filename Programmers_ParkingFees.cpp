// Start (2023-10-26 18:30)
// End (202-10-36 19:20) - ����

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

typedef unsigned int UINT;

using namespace std;

// string���� ���� �ð��� int�� ��� �� ��ȯ
int time_diff(string in, string out)
{
    // stoi : string to int
    // substr : ���ڿ� �ڸ��� �Լ�, substr(���� ����, �� �� �ڸ�����)
    int h1 = stoi(in.substr(0, 2));
    int m1 = stoi(in.substr(3, 2));
    int h2 = stoi(out.substr(0, 2));
    int m2 = stoi(out.substr(3, 2));

    int diff = (h2 - h1) * 60 + (m2 - m1);

    return diff;
}

// fees[0] : �⺻ �ð�
// fees[1] : �⺻ ���
// fees[2] : ���� �ð�(��)
// fees[3] : ���� ���(��)
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
        if (i.second.size() & 1) // ��Ʈ �������� Ȧ���� �Ǻ�
            i.second.push_back("23:59");

        vector<string> info = i.second;
        int total = 0;
        for (UINT i = 0; i < (info.size() - 1); i += 2)
            total += time_diff(info[i], info[i + 1]);

        int price = fees[1];    // �⺻ ���
        if (total > fees[0])
            price += (int)ceil((total - (double)fees[0]) / fees[2]) * fees[3];
        // ceil : �ø� ���ִ� �Լ� / �Ǽ� -> ����
        // (double) ĳ������ �ʿ��� ���� : ceil �Լ��� ���ڷ� double ���� �ޱ� ����

        answer.push_back(price);
    }

    return answer;
}

int main()
{

    return 0;
}

/*/// <param name="fees"> : ���ǥ</param>
/// <param name="records"> : ��/���� ���</param>
/// <returns></returns>
vector<int> solution(vector<int> fees, vector<string> records)  // fees : ���ǥ , records : ��/���� ���
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