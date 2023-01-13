#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX_LEN 1 << 30

int n;		// 2 <= n <= 16
int w[17][17];
int dp[17][(1 << 16) + 1];
int finish;

int min(int a, int b)
{
	return b > a ? a : b;
}

int visited(int idx, int visit_state)
{
	return (visit_state & (1 << idx)) == 0 ? 0 : 1;
}

int getMinLen(int idx, int visit_state)
{
	if (visit_state == finish)
	{
		return w[idx][1] != 0 ? w[idx][1] : MAX_LEN;
	}
	if (dp[idx][visit_state] != -1) return dp[idx][visit_state];

	int min_len = MAX_LEN;
	for (int i = 1; i <= n; i++)
	{
		if (visited(i - 1, visit_state)) continue;
		if (w[idx][i] == 0) continue;
		int cur_len = getMinLen(i, visit_state | (1 << (i - 1))) + w[idx][i];
		min_len = min(min_len, cur_len);
	}

	dp[idx][visit_state] = min_len;

	return dp[idx][visit_state];
}

void input()
{
	scanf("%d", &n);
	finish = (1 << n) - 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &w[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	printf("%d\n", getMinLen(1, 1));

	return 0;
}