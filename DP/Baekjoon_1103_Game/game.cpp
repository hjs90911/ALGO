#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const int INF = 1 << 30;
const int MAX = 51;
const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

int n, m;		// 1 <= n, m <= 50
int board[MAX][MAX];
int visited[MAX][MAX];
int dp[MAX][MAX];

int max(int a, int b)
{
	return a > b ? a : b;
}

int countMove(int y, int x)
{
	if (visited[y][x] == 1) return INF;
	if (dp[y][x] != -1)	return dp[y][x];

	visited[y][x] = 1;
	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		int l = board[y][x];
		int ny = y + dy[i] * l;
		int nx = x + dx[i] * l;

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (board[ny][nx] == 0) continue;
		int ncnt = countMove(ny, nx);
		cnt = max(cnt, ncnt + 1);
	}
	visited[y][x] = 0;

	return dp[y][x] = cnt;
}

void input()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		char line[51];
		scanf("%s", line);
		for (int j = 0; j < m; j++)
		{
			board[i][j] = line[j] == 'H' ? 0 : (int)(line[j] - '0');
			visited[i][j] = 0;
			dp[i][j] = -1;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	//int tc = 1;
	for (int test_case = 1; test_case <= T; test_case++)
	//for (int test_case = 1; test_case <= tc; test_case++)
	{
		input();
		//if (test_case < tc) continue;
		int ans = countMove(0, 0);
		printf("%d\n", ans >= INF ? -1 : ans);
	}

	return 0;
}