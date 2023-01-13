#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef long long ll;

ll n;			// 0 <= n <= 100000
ll m;			// 1 <= m <= 1000000000
ll t[1000000];
ll max_time;

void input()
{
	cin >> n >> m;

	max_time = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		max_time = max(max_time, t[i]);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	//for (int test_case = 1; test_case <= 1; test_case++)
	{
		input();

		ll start = 0, end = max_time * m;

		while (start <= end)
		{
			ll mid = (start + end) / 2;
			ll people_num = 0;
			for (int i = 0; i < n; i++)
			{
				people_num += mid / t[i];
			}

			if (people_num < m)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		cout << start << '\n';
	}

	return 0;
}