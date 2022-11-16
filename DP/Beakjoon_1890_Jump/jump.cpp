#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n;
int board[100][100];
long long dp[100][100];

long long countRoute(int y, int x)
{
	if (y == n - 1 && x == n - 1)
		return 1;
	if (dp[y][x] != -1)
		return dp[y][x];

	int cnt = 0;
	int jump_dist = board[y][x];
	if (jump_dist == 0)
		return 0;
	if (y + jump_dist < n)
		cnt += countRoute(y + jump_dist, x);
	if (x + jump_dist < n)
		cnt += countRoute(y, x + jump_dist);

	dp[y][x] = cnt;

	return dp[y][x];
}

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &board[i][j]);
			dp[i][j] = -1;
		}
	}
}

int main()
{
	input();
	printf("%lld\n", countRoute(0, 0));

	return 0;
}