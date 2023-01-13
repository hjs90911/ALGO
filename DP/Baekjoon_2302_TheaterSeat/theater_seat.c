#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define VIP 1

int n;		// 1 <= n <= 40
int m;		// 0 <= m <= n
int vip[41];
int dp[41];

void input()
{
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &vip[i]);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	input();

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int answer = 1;
	for (int i = 1; i <= m; i++)
	{
		answer *= dp[vip[i] - vip[i - 1] - 1];
	}

	answer *= dp[n - vip[m]];

	printf("%d\n", answer);

	return 0;
}