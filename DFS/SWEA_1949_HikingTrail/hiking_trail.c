#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _Node
{
	int y;
	int x;
} Node;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n;				// 1 <= n <= 20
int k;				// 1 <= k <= 5
int map[8][8];
int visited[8][8];

Node peak[5];
int peak_num;

int max_len;

void dfs(int y, int x, int len)
{
	max_len = max_len < len ? len : max_len;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx] == 1) continue;
		if (map[ny][nx] >= map[y][x]) continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, len + 1);
		visited[ny][nx] = 0;
	}
}

void findRoute()
{
	for (int i = 0; i < peak_num; i++)
	{
		int y = peak[i].y;
		int x = peak[i].x;
		visited[y][x] = 1;
		dfs(y, x, 1);
		visited[y][x] = 0;
	}
}

void cutPeak()
{
	for (int d = 0; d <= k; d++)
	{
		if (d == 0)
		{
			findRoute();
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					map[i][j] -= d;
					findRoute();
					map[i][j] += d;
				}
			}
		}
	}
}


void input()
{
	scanf("%d %d", &n, &k);

	int highest_peak = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
			map[i][j] = map[i][j];
			visited[i][j] = 0;

			if (highest_peak < map[i][j])
			{
				peak_num = 0;
				highest_peak = map[i][j];
			}

			if (highest_peak <= map[i][j])
			{
				peak[peak_num++] = (Node){ i, j };
			}
		}
	}
	max_len = 0;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		input();
		cutPeak();

		printf("#%d %d\n", test_case, max_len);
	}

	return 0;
}