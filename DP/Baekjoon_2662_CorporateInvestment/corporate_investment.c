#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;			// 1 <= n <= 300
int m;			// 1 <= m <= 20
int p[301][21];
int dp[301][21];
int company[301][21];

int max(int a, int b)
{
	return a > b ? a : b;
}

int getPrice(int invest_price, int company_idx)
{
	if (company_idx == m + 1 || invest_price == 0)
		return 0;
	if (dp[invest_price][company_idx] != 0)
		return dp[invest_price][company_idx];

	int max_price = 0;
	for (int i = 0; i <= n; i++)
	{
		if (invest_price - i < 0) continue;
		int next_max_price = getPrice(invest_price - i, company_idx + 1) + p[i][company_idx];
		if (max_price < next_max_price)
		{
			max_price = next_max_price;
			company[invest_price][company_idx] = i;
		}
	}

	return dp[invest_price][company_idx] = max_price;
}

void input()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		int idx;
		scanf("%d", &idx);
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &p[i][j]);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();

	int max_price = getPrice(n, 1);
	
	printf("%d\n", max_price);
	for (int i = 1; i <= m; i++)
	{
		printf("%d ", company[n][i]);
		n -= company[n][i];
	}

	return 0;
}