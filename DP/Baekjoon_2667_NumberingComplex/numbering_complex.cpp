#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

int n;
int map[25][25];
int dp[25][25];
int visited[25][25];
int num[625];
int num_index;

int getLength(int y, int x)
{
	if (dp[y][x] != -1) return dp[y][x];

	int len = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] == 0) continue;
		visited[ny][nx] = 1;
		len += getLength(ny, nx);
	}

	return dp[y][x] = len;
}

void move()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0) continue;
			if (dp[i][j] != -1) continue;
			visited[i][j] = 1;
			num[num_index++] = getLength(i, j);
		}
	}
}

void input()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char line[30];
		scanf("%s", line);
		for (int j = 0; j < n; j++)
		{
			map[i][j] = (int)(line[j] - '0');
			dp[i][j] = -1;
			visited[i][j] = 0;
		}
	}
	num_index = 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	move();
	std::sort(num, num + num_index);

	printf("%d\n", num_index);
	for (int i = 0; i < num_index; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;
}