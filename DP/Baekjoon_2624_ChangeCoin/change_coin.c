#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t;		// 0 < t <= 10000
int k;		// 0 < k <= 100
int p[101];
int n[101];
int coin_num;
int dp[10001][101];

int getCount(int amount, int idx)
{
	if (amount == 0) return dp[amount][idx] = 1;
	if (idx > k) return dp[amount][idx] = 0;
	if (dp[amount][idx] != 0) return dp[amount][idx];

	int cnt = 0;
	for (int i = 0; i <= n[idx]; i++)
	{
		if (amount - p[i] * i >= 0)
			cnt += getCount(amount - p[i] * i, idx + 1);
	}

	return dp[amount][idx] = cnt;
}

void input()
{
	scanf("%d", &t);
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &p[i], &n[i]);
		coin_num += n[i];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	int count = getCount(t, 0);
	printf("%d\n", count);

	return 0;
}