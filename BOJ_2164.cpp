// Start (2023-10-11 12:40)
// End (2023-10-11 13:05)

#include <iostream>
#include <list>

int main()
{
	int N;
	std::cin >> N;

	std::list<int> Cards;

	for (int i = N; i >= 1; i--)
		Cards.push_back(i);		// N N-1 ... 2 1

	while (Cards.size() > 1)
	{
		Cards.pop_back();	// �� �� ���� ����

		int temp = Cards.back(); // �� �� ���� -> �� ������ �̵�
		Cards.pop_back();

		Cards.push_front(temp);
	}

	std::cout << Cards.front();

	return 0;
}