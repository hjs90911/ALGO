#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

const int MAX = 16;
const int INF = 1 << MAX;

int n;			// 1 <= n <= 16
int power_cost[MAX][MAX];
int plant_state;
int dp[1 << MAX];				// dp[b] = a: minimum cost is a when bit state is b
int active_plant_num;
int p;

int min(int a, int b)
{
	return b > a ? a : b;
}

int getMinCost(int num, int state)
{
	if (num >= p) return 0;
	if (dp[state] != -1) return dp[state];

	int cost = INF;
	for (int i = 0; i < n; i++)						// find active power plant
	{
		if ((state & (1 << i)) == 0) continue;
		for (int j = 0; j < n; j++)					// find inactive power plant
		{
			if ((state & (1 << j)) != 0) continue;
			int next_state = state | (1 << j);
			cost = min(cost, getMinCost(num + 1, next_state) + power_cost[i][j]);
		}
	}

	return dp[state] = cost;
}

void input()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &power_cost[i][j]);
		}
	}

	plant_state = 0;
	active_plant_num = 0;
	char line[20];
	scanf("%s", line);
	for (int i = 0; i < n; i++)
	{
		int bit;
		if (line[i] == 'Y')
		{
			bit = 1;
			active_plant_num++;
		}
		else
		{
			bit = 0;
		}
		plant_state |= (bit << i);
	}

	scanf("%d", &p);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	int tc = 7;
	for (int test_case = 1; test_case <= T; test_case++)
	//for (int test_case = 1; test_case <= tc; test_case++)
	{
		input();
		//if (test_case < tc) continue;

		int min_cost = getMinCost(active_plant_num, plant_state);
		printf("%d\n", min_cost == INF ? -1 : min_cost);
	}

	return 0;
}