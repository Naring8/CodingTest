// Start (2023-10-22 03:19)
// End (2023-10-22 03:45)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    // �켱����ť ��������
    priority_queue<int, vector<int>, greater<> > pq(scoville.begin(), scoville.end());

    // ������ �ּ� 2�� �̻��̰� ���� �ȸſ� ������ K���� ������������ �ݺ�
    while (pq.size() > 1 && pq.top() < K) 
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        // �ΰ��� ������ ��� �켱���� ť�� �߰�
        pq.push(first + (second * 2));

        answer++;
    }

    // ��� ������ ������ �� �켱���� ť�� ���� ���� ���� ������ K���� �۴ٸ� -1�� ����
    if (pq.top() < K)
        return -1;

    return answer;
}

int main()
{
    cout << solution({ 1, 2, 3, 9, 10, 12 }, 7);

    return 0;
}


//#include <iostream>
//
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int SpecialCase(const int& a, const int& b)
//{
//    return (a + (b * 2));
//}
//
//bool Check(const vector<int>& scoville, const int& K)
//{
//    for (int i = 0; i < scoville.size(); i++)
//        if (scoville[i] < K)
//            return false;
//
//    return true;
//}
//
//int solution(vector<int> scoville, int K)
//{
//    int answer = 0;
//
//    sort(scoville.begin(), scoville.end(), greater<>());
//    while (!Check(scoville, K))
//    {
//        if (scoville.size() < 2)
//        {
//            answer = -1;
//            break;
//        }
//
//        scoville.back();
//        int temp = SpecialCase(scoville[scoville.size() - 1], scoville[scoville.size() - 2]);
//        scoville.pop_back();
//        scoville[scoville.size() - 1] = temp;
//
//        sort(scoville.begin(), scoville.end(), greater<>());
//
//        answer += 1;
//    }
//
//    return answer;
//}
//
//int main()
//{
//    cout << solution({ 1, 2, 3, 9, 10, 12 }, 7);
//
//    return 0;
//}