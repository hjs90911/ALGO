#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n;			// 1 <= n <= 100
int k;			// 1 <= k <= 10000
int coins[101];
int dp[10001];

void input()
{
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coins[i]);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	//for (int test_case = 1; test_case <= T; test_case++)
	for (int test_case = 1; test_case <= 2; test_case++)
	{
		input();
		if (test_case < 2) continue;

		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = coins[i]; j <= k; j++)
			{
				dp[j] += dp[(j - coins[i])];
			}
		}

		printf("%d\n", dp[k]);
	}

	return 0;
}