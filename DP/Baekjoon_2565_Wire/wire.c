#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int wire[501];
int dp[501];
int min_wire_num, max_wire_num;

void input()
{
	scanf("%d", &n);

	min_wire_num = 501;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		wire[a] = b;
		max_wire_num = a > max_wire_num ? a : max_wire_num;
		min_wire_num = a < min_wire_num ? a : min_wire_num;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	input();

	for (int i = min_wire_num; i <= max_wire_num; i++)
	{
		if (wire[i] == 0) continue;
		dp[i] = 1;
		for (int j = min_wire_num; j < i; j++)
		{
			if (wire[j] == 0) continue;
			if (wire[i] > wire[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
		}
	}
	
	int max_cnt = 0;
	for (int i = min_wire_num; i <= max_wire_num; i++)
	{
		if (dp[i] == 0) continue;
		max_cnt = max_cnt < dp[i] ? dp[i] : max_cnt;
	}

	printf("%d\n", n - max_cnt);

	return 0;
}