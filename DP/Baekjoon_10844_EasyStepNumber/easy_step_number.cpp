#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using ll = long long;

const ll MOD = 1000000000;
int n;
ll dp[101][10];

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	//for (int test_case = 1; test_case <= 1; test_case++)
	{
		scanf("%d", &n);

		for (int i = 1; i < 10; i++)
		{
			dp[1][i] = 1;
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (j == 0) dp[i][j] = dp[i - 1][j + 1];
				else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

				dp[i][j] %= MOD;
			}
		}

		ll ans = 0;
		for (int i = 0; i < 10; i++)
		{
			ans = (ans + dp[n][i]) % MOD;
		}

		printf("%lld\n", ans);
	}

	return 0;
}