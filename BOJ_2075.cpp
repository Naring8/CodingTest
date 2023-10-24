// Start (2023-10-24 22:30)
// End (2023-10-24 23:00)

/*#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> nums;
	for (int i = 0; i < N * N; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end(), greater<>());

	cout << nums[N - 1];

	return 0;
}*/

/*#include <iostream>
#include <algorithm>

using namespace std;

int arr[2250010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N * N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N * N, greater<>());
    cout << arr[N - 1];

    return 0;
}*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            cin >> input;
            pq.push(input);
        }

        //상위 n개만 남긴다
        while (pq.size() > N)
        {
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}