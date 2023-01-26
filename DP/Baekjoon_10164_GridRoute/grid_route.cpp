#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const int MAX = 16;
int n, m;		// 1 <= n, m <= 15
int k;
int ky, kx;
int grid[MAX][MAX];
int dp[MAX][MAX];

void input()
{
	scanf("%d %d %d", &n, &m, &k);
	ky = kx = MAX - 1;

	int num = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			grid[i][j] = num;

			if (num == k)
			{
				ky = i, kx = j;
			}
			num++;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	int tc = 6;
	//for (int test_case = 1; test_case <= T; test_case++)
	for (int test_case = 1; test_case <= tc; test_case++)
	{
		input();
		if (test_case < tc) continue;

		dp[1][1] = 1;
		for (int i = 1; i <= ky; i++)
		{
			for (int j = 1; j <= kx; j++)
			{
				if (i == 1)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}

		for (int i = ky; i <= n; i++)
		{
			for (int j = kx; j <= m; j++)
			{
				if (i == 1)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}

		printf("%d\n", dp[n][m]);
	}

	return 0;
}