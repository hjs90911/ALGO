#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int k;
int w[101];
int v[101];
int dp[101][100001];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &w[i], &v[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - w[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	printf("%d\n", dp[n][k]);

	return 0;
}