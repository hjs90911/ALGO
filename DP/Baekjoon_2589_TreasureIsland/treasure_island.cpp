#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

struct Node
{
	int y;
	int x;
};

int l, w;
char map[50][50];
int visited[50][50];
int dp[50][50];
int max_len;

void initVisited()
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			visited[i][j] = 0;
			dp[i][j] = -1;
		}
	}
}

void move(int y, int x)
{
	std::queue<Node> q;
	q.push({ y, x });
	int min_time = 0;

	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		int cl = dp[cy][cx];

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nl = cl + 1;

			if (ny < 0 || ny >= l || nx < 0 || nx >= w) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == 'W') continue;
			visited[ny][nx] = 1;
			dp[ny][nx] = nl;
			min_time = min_time < dp[ny][nx] ? dp[ny][nx] : min_time;

			q.push({ ny, nx });
		}
		q.pop();
	}

	max_len = max_len > min_time ? max_len : min_time;
}

void findMaxLen()
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (map[i][j] == 'W') continue;
			visited[i][j] = 1;
			dp[i][j] = 0;
			move(i, j);
			initVisited();
		}
	}
}

void input()
{
	scanf("%d %d", &l, &w);

	for (int i = 0; i < l; i++)
	{
		char line[51];
		scanf("%s", line);
		for (int j = 0; j < w; j++)
		{
			map[i][j] = line[j];
			visited[i][j] = 0;
			dp[i][j] = -1;
		}
	}
	max_len = 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	findMaxLen();

	printf("%d\n", max_len);

	return 0;
}