// 22:55 ~ 
#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned int uint;

uint Z(int N, int r, int c)
{
	uint quad = pow(2, N + 1);
	uint halfN = pow(2, N - 1);
	uint halfNSqr = halfN * halfN;

	uint total = 0;

	{
		// 0
		if (r < halfN && c < halfN)
			total += 0;

		// 1
		else if (r < halfN && c >= halfN)
		{
			total += halfNSqr;
			c -= halfN;
		}

		// 2
		else if (r >= halfN && c < halfN)
		{
			total += halfNSqr * 2;
			r -= halfN;
		}


		// 3
		else if (r >= halfN && c >= halfN)
		{
			total += halfNSqr * 3;
			c -= halfN; r -= halfN;
		}
	}

	// N == 0 이 될 때까지 재귀
	{
		if (N != 0)
			total += Z(N - 1, r, c);
	}

	return total;
}

int main()
{
	int N, r, c; cin >> N >> r >> c;

	cout << Z(N, r, c);

	return 0;
}