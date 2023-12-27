// 17:22 ~ 17:50 : TLE
#include <iostream>
#include <vector>

using namespace std;

vector<int> mArray; vector<int> sArray;
vector<int> AmArray; vector<int> AsArray;

void InputNum(vector<int>& dest, int size)
{
	while (size--)
	{
		int num; cin >> num;
		dest.push_back(num);
	}
}

void MakeAllCom(const vector<int>& base, vector<int>& dest)
{
	for (int i = 0; i < base.size(); i++)
	{
		int inputNum = base[i];

		for (int j = i + 1; j < base.size(); j++)
		{
			dest.push_back(inputNum);
			inputNum += base[j];
		}
		dest.push_back(inputNum);
	}
}

int main()
{
	// 구하려는 수
	int T; cin >> T;

	int count = 0;

	// 배열
	{
		int mSize; cin >> mSize;
		InputNum(mArray, mSize);
	}
	// 부 배열
	{
		int sSize; cin >> sSize;
		InputNum(sArray, sSize);
	}

	MakeAllCom(mArray, AmArray); MakeAllCom(sArray, AsArray);

	for (int i = 0; i < AmArray.size(); i++)
	{
		for (int j = 0; j < AsArray.size(); j++)
		{
			if ((AmArray[i] + AsArray[j]) == T)
				count++;
		}
	}

	cout << count;

	return 0;
}