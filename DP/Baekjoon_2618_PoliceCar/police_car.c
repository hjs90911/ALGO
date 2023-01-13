#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

typedef struct
{
	int y;
	int x;
} Node;

int n;
int w;
Node cases[1001];
Node a[1001];
Node b[1001];
int dp[1001][1001];
int police_order[1001];

int min(int a, int b)
{
	return b > a ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int abs(int a)
{
	return a < 0 ? -a : a;
}

int getLen(Node n1, Node n2)
{
	return abs(n1.y - n2.y) + abs(n1.x - n2.x);
}

void setPoliceOrder(int police_1, int police_2)
{
	if (police_1 == w || police_2 == w) return;

	int next_case = max(police_1, police_2) + 1;
	int	l1 = dp[next_case][police_2] + getLen(cases[next_case], a[police_1]);
	int	l2 = dp[police_1][next_case] + getLen(cases[next_case], b[police_2]);

	if (l1 < l2)
	{
		police_order[next_case] = 1;
		setPoliceOrder(next_case, police_2);
	}
	else
	{
		police_order[next_case] = 2;
		setPoliceOrder(police_1, next_case);
	}
}

int getMinLen(int police_1, int police_2)
{
	if (police_1 == w || police_2 == w) return 0;
	if (dp[police_1][police_2] != -1) return dp[police_1][police_2];

	int next_case = max(police_1, police_2) + 1;
	int	l1 = getMinLen(next_case, police_2) + getLen(cases[next_case], a[police_1]);
	int	l2 = getMinLen(police_1, next_case) + getLen(cases[next_case], b[police_2]);

	return dp[police_1][police_2] = min(l1, l2);
}

void input()
{
	scanf("%d", &n);
	scanf("%d", &w);

	for (int i = 1; i <= w; i++)
	{
		scanf("%d %d", &cases[i].y, &cases[i].x);
		a[i] = b[i] = cases[i];
	}
	a[0] = (Node){ 1, 1 };
	b[0] = (Node){ n, n };

	memset(dp, -1, sizeof(dp));
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	int tc = 3;
	//for (int test_case = 1; test_case <= T; test_case++)
	for (int test_case = 1; test_case <= tc; test_case++)
	{
		input();
		//if (test_case < tc) continue;
		printf("%d\n", getMinLen(0, 0));
		setPoliceOrder(0, 0);
		for (int i = 1; i <= w; i++)
		{
			printf("%d\n", police_order[i]);
		}
	}

	return 0;
}