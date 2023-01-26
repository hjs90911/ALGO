#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

const int INF = 100 * 1000;

struct City
{
	int cost;
	int num;
};

int c, n;			// 1 <= c <= 1000, 1 <= n <= 20
City city[20];
int dp[1001];

int min(int a, int b)
{
	return b > a ? a : b;
}

int getMinCost(int num)
{
	if (num <= 0) return 0;
	if (dp[num] != -1) return dp[num];

	int money = INF;
	for (int i = 0; i < n; i++)
	{
		money = min(money, getMinCost(num - city[i].num) + city[i].cost);
	}

	return dp[num] = money;
}

void input()
{
	scanf("%d %d", &c, &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &city[i].cost, &city[i].num);
	}

	memset(dp, -1, sizeof(dp));
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
		int min_cost = getMinCost(c);

		printf("%d\n", min_cost);
	}

	return 0;
}