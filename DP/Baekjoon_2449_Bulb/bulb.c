#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 1 << 30

int n;			// 0 <= n <= 200
int k;			// 1 <= k <= 20
int bulb[201];
int dp[201][201];

void input()
{
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &bulb[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = INF;
		}
		dp[i][i] = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();

	for (int size = 2; size <= n; size++)
	{
		for (int start = 1; start <= n - size + 1; start++)
		{
			int end = start + size - 1;
			for (int mid = start; mid < end; mid++)
			{
				int new_value = dp[start][mid] + dp[mid + 1][end];
				if (bulb[start] != bulb[mid + 1]) new_value++;
				if (dp[start][end] > new_value) dp[start][end] = new_value;
			}
		}
	}

	printf("%d\n", dp[1][n]);

	return 0;
}