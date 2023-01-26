#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

const int EAST = 1;
const int WEST = 2;
const int SOUTH = 3;
const int NORTH = 4;

const int dy[] = { 0, 0, 0, 1, -1 };
const int dx[] = { 0, 1, -1, 0, 0 };

const int MAX = 1 << 30;

struct Node
{
	int y;
	int x;
	int dir;
};

int m, n;			// m, n <= 100
int track[101][101];
Node start, finish;
int dp[101][101][5];
bool visited[101][101][5];

int rotate(int dir, bool isClockwise)
{
	int ndir = 0;
	switch (dir)
	{
	case EAST:
		ndir = isClockwise ? SOUTH : NORTH;
		break;
	case WEST:
		ndir = isClockwise ? NORTH : SOUTH;
		break;
	case SOUTH:
		ndir = isClockwise ? WEST : EAST;
		break;
	case NORTH:
		ndir = isClockwise ? EAST : WEST;
		break;
	}

	return ndir;
}

void solve()
{
	queue<Node> q;
	q.push(start);
	dp[start.y][start.x][start.dir] = 0;
	visited[start.y][start.x][start.dir] = true;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		int cnt = dp[y][x][dir];

		int ny, nx, ndir;
		int ncnt = cnt + 1;
		// cmd 1
		for (int i = 1; i <= 3; i++)
		{
			ndir = dir;
			ny = y + dy[dir] * i;
			nx = x + dx[dir] * i;

			if (ny < 1 || ny > m || nx < 1 || nx > n) continue;
			if (visited[ny][nx][ndir]) continue;
			if (track[ny][nx] == 1) break;

			visited[ny][nx][ndir] = true;
			dp[ny][nx][ndir] = ncnt;
			q.push({ ny, nx, ndir });
		}

		// cmd 2
		for (int i = 0; i < 2; i++)
		{
			bool isClockwise = i == 0 ? false : true;
			ny = y, nx = x;
			ndir = rotate(dir, isClockwise);
			if (visited[ny][nx][ndir]) continue;

			visited[ny][nx][ndir] = true;
			dp[ny][nx][ndir] = ncnt;
			q.push({ ny, nx, ndir });
		}
		
		q.pop();
	}
}

void input()
{
	ifstream cin("input.txt");
	cin >> m >> n;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> track[i][j];

			for (int k = 1; k <= 4; k++)
			{
				dp[i][j][k] = MAX;
				visited[i][j][k] = false;
			}
		}
	}

	int y, x, dir;
	cin >> y >> x >> dir;
	start = { y, x, dir };
	cin >> y >> x >> dir;
	finish = { y, x, dir };
}

int main()
{
	ifstream cin("input.txt");
	for (int test_case = 0; test_case < 6; test_case++)
	//for (int test_case = 0; test_case < 1; test_case++)
	{
		//input();
		cin >> m >> n;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> track[i][j];
				
				for (int k = 1; k <= 4; k++)
				{
					dp[i][j][k] = MAX;
					visited[i][j][k] = false;
				}
			}
		}

		int y, x, dir;
		cin >> y >> x >> dir;
		start = { y, x, dir };
		cin >> y >> x >> dir;
		finish = { y, x, dir };

		//if (test_case < tc) continue;
		solve();

		cout << dp[finish.y][finish.x][finish.dir] << '\n';
	}

	return 0;
}