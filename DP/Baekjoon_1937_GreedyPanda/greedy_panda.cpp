#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n;
int forest[500][500];
int dp[500][500];
int max_len;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int max(int a, int b)
{
	return a > b ? a : b;
}

int getLen(int y, int x)
{
	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (forest[ny][nx] <= forest[y][x]) continue;

		dp[y][x] = max(dp[y][x], getLen(ny, nx) + 1);
	}

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
			scanf("%d", &forest[i][j]);
			dp[i][j] = -1;
		}
	}
}

int main()
{
	input();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			max_len = max(max_len, getLen(i, j));
		}
	}

	printf("%d\n", max_len);

	return 0;
}