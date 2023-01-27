#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int weight_num;
int weight[30];
int marble_num;
int marble[7];
int dp[31][15001];

int abs(int a)
{
	return a > 0 ? a : -a;
}

void printMarble()
{
	for (int i = 0; i < marble_num; i++)
	{
		int marble_weight = marble[i];
		if (marble_weight > 15000) printf("N ");
		else printf(dp[weight_num][marble_weight] == 1 ? "Y " : "N ");
	}
	printf("\n");
}

void selectWeight(int idx, int cur_weight)
{
	if (idx > weight_num || dp[idx][cur_weight]) return;
	dp[idx][cur_weight] = 1;

	selectWeight(idx + 1, cur_weight);
	selectWeight(idx + 1, cur_weight + weight[idx]);
	selectWeight(idx + 1, abs(cur_weight - weight[idx]));
}

void input()
{
	scanf("%d", &weight_num);

	for (int i = 0; i < weight_num; i++)
	{
		scanf("%d", &weight[i]);
	}

	scanf("%d", &marble_num);

	for (int i = 0; i < marble_num; i++)
	{
		scanf("%d", &marble[i]);
	}

	for (int i = 1; i <= 30; i++)
	{
		for (int j = 1; j <= 40000; j++)
		{
			dp[i][j] = 0;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	int tc = 1;
	//for (int test_case = 1; test_case <= T; test_case++)
	for (int test_case = 1; test_case <= tc; test_case++)
	{
		input();
		if (test_case < tc) continue;
		selectWeight(0, 0);
		printMarble();
	}

	return 0;
}