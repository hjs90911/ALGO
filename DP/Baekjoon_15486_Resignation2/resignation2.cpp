#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

int n;
int t[51];
int p[1001];
int dp[1600001];

int max(int a, int b)
{
	return a > b ? a : b;
}

void input()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &t[i], &p[i]);
	}

	memset(dp, 0, sizeof(dp));
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	int tc = 2;
	for (int test_case = 1; test_case <= T; test_case++)
	//for (int test_case = 1; test_case <= tc; test_case++)
	{
		input();
		//if (test_case < tc) continue;

		for (int i = 1; i <= n; i++)
		{
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
			dp[i + 1] = max(dp[i + 1], dp[i]);
		}

		printf("%d\n", dp[n + 1]);
	}

	return 0;
}