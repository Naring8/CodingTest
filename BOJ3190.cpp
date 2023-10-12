// Start (2023-10-12 21:45)
// End (2023-10-12 22:43) - 실패

#include <iostream>
#include <vector>
#include <deque>

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

int main()
{
	int N, K;
	std::cin >> N;
	std::cin >> K;
	std::vector<std::pair<int, int>> Apples;
	for (int i = 0; i < K; i++)
	{
		int R, C;
		std::cin >> R >> C;
		Apples.push_back({ R, C });
	}

	int L;
	std::cin >> L;
	std::deque<std::pair<int, char>> Move;
	for (int i = 0; i < L; i++)
	{
		int X;	// int : time
		char C; // char : turn(90 deg)
		std::cin >> X >> C;
		Move.push_back({ X, C });
	}

	std::deque<std::pair<int, int>> Snake;	// 머리 몸 분리
	Snake.resize(1, { 0, 0 });

	Direction SnakeDirection = Direction::RIGHT;

	int TotalTime = 0;

	// Implementation
	{
		while (1)
		{
			// Snake Move
			{
				// 1
				Snake.push_back(Snake.back());
				switch (SnakeDirection)
				{
				case UP:
					Snake.emplace_front(std::make_pair(Snake.front().first, Snake.front().second - 1));
					break;
				case DOWN:
					Snake.emplace_front(std::make_pair(Snake.front().first, Snake.front().second + 1));
					break;
				case LEFT:
					Snake.emplace_front(std::make_pair(Snake.front().first - 1, Snake.front().second));
					break;
				case RIGHT:
					Snake.emplace_front(std::make_pair(Snake.front().first + 1, Snake.front().second));
					break;
				}

				// 2	Died
				if (Snake.front().first >= N || Snake.front().first < 0)
					std::cout << TotalTime;
				else if (Snake.front().second >= N || Snake.front().second < 0)
					std::cout << TotalTime;
				else
				{
					for (int i = 1; i < Snake.size(); i++)
					{
						if (Snake.front().first == (Snake.at(i).first) && Snake.front().second == (Snake.at(i).second))
							std::cout << TotalTime;
					}
				}

				// 3 IsThereApple
				for (int i = 0; i < K; i++)
				{
					if (Snake.front().first == Apples[i].first && Snake.front().second == Apples[i].second)
					{

					}
					else
						Snake.pop_back();
				}

			}

			TotalTime++;
			// MovingDirection
			if (TotalTime == Move.front().first)
			{
				if (Move.front().second == 'D')
				{
					switch (SnakeDirection)
					{
					case UP:
						SnakeDirection = Direction::RIGHT;
						break;
					case DOWN:
						SnakeDirection = Direction::LEFT;
						break;
					case LEFT:
						SnakeDirection = Direction::UP;
						break;
					case RIGHT:
						SnakeDirection = Direction::DOWN;
						break;
					}
				}
				else if (Move.front().second == 'L')
				{
					switch (SnakeDirection)
					{
					case UP:
						SnakeDirection = Direction::LEFT;
						break;
					case DOWN:
						SnakeDirection = Direction::RIGHT;
						break;
					case LEFT:
						SnakeDirection = Direction::DOWN;
						break;
					case RIGHT:
						SnakeDirection = Direction::UP;
						break;
					}
				}
			}
		}
	}
	return 0;
}