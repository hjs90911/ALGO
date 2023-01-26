#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int n;			// 3 <= n <= 16
int grid[17][17];
int dp[17][17][3];		// 0: horizontal, 1: vertical, 2: diagonal

void input()
{
	scanf("%d", &n);

	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	int tc = 3;
	for (int test_case = 1; test_case <= T; test_case++)
	//for (int test_case = 1; test_case <= tc; test_case++)
	{
		input();
		//if (test_case < tc) continue;

		dp[1][2][0] = 1;
		for (int i = 3; i <= n; i++)
		{
			if (grid[1][i] == 0)
				dp[1][i][0] = dp[1][i - 1][0];
		}
		
		for (int i = 2; i <= n; i++)
		{
			for (int j = 3; j <= n; j++)
			{
				if (grid[i][j] == 0 && grid[i - 1][j] == 0 && grid[i][j - 1] == 0)
				{
					for (int k = 0; k < 3; k++)
					{
						dp[i][j][2] += dp[i - 1][j - 1][k];
					}
				}

				if (grid[i][j] == 0)
				{
					dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
					dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < 3; i++)
		{
			cnt += dp[n][n][i];
		}

		printf("%d\n", cnt);
	}

	return 0;
}