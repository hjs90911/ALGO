#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };

typedef struct _Node
{
	int y;
	int x;
} Node;

int m, n;	// 1 <= m, n <= 100
int k;		// number of waste
int path[100][100];
int checked[100][100];
Node waste[10000];
int max_size;

int max(int a, int b)
{
	return a > b ? a : b;
}

int getWasteSize(int y, int x)
{
	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (checked[ny][nx] == 1) continue;

		checked[ny][nx] = 1;
		if (path[ny][nx] == 1)
		{
			cnt += getWasteSize(ny, nx);
		}
	}

	return cnt;
}

void countWaste()
{
	for (int i = 0; i < k; i++)
	{
		int y = waste[i].y;
		int x = waste[i].x;

		if (checked[y][x] != 1)
		{
			checked[y][x] = 1;
			max_size = max(max_size, getWasteSize(y, x));
		}
	}
}

void input()
{
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++)
	{
		memset(path[i], 0, sizeof(int) * m);
		memset(checked[i], 0, sizeof(int) * m);
	}

	for (int i = 0; i < k; i++)
	{
		int y, x;
		scanf("%d %d", &y, &x);
		path[y - 1][x - 1] = 1;
		waste[i] = (Node){ y - 1, x - 1 };
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	countWaste();
	printf("%d\n", max_size);

	return 0;
}