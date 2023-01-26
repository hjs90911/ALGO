#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>

const int MAX = 1001;
int n, k;
int t[MAX];
std::vector<int> tech[MAX];
int dp[MAX];
int ans_idx;

int max(int a, int b)
{
	return a > b ? a : b;
}

int getBuildTime(int idx)
{
	if (dp[idx] != -1) return dp[idx];
	int build_time = 0;
	for (int i = 0; i < tech[idx].size(); i++)
	{
		int next_idx = tech[idx][i];
		build_time = max(build_time, getBuildTime(next_idx));
	}
	build_time += t[idx];

	return dp[idx] = build_time;
}

void input()
{
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i]);
		dp[i] = -1;
	}

	memset(tech, 0, sizeof(tech));
	for (int i = 0; i < k; i++)
	{
		int p1, p2;
		scanf("%d %d", &p1, &p2);
		tech[p2].push_back(p1);
	}

	scanf("%d", &ans_idx);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	int tc = 8;
	for (int test_case = 1; test_case <= T; test_case++)
	//for (int test_case = 1; test_case <= tc; test_case++)
	{
		input();
		//if (test_case < tc) continue;

		printf("%d\n", getBuildTime(ans_idx));
	}

	return 0;
}