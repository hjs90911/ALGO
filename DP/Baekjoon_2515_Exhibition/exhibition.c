#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int h;
	int c;
} Picture;

int n, s;
Picture picture[300001];
int diff[300001];
int dp[300001];

int compare(const void* a, const void* b)
{
	Picture* p1 = (Picture*)a;
	Picture* p2 = (Picture*)b;

	return p1->h - p2->h;
}

void input()
{
	scanf("%d %d", &n, &s);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &picture[i].h, &picture[i].c);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		input();
		qsort(picture, n, sizeof(Picture), compare);

		for (int i = 1; i <= n; i++)
		{
			for (diff[i] = diff[i - 1] + 1; diff[i] < i; diff[i]++)
			{
				if (picture[i].h - picture[diff[i]].h < s) break;
			}
			diff[i]--;
		}

		for (int i = 1; i <= n; i++)
		{
			dp[i] = dp[diff[i]] + picture[i].c;
			dp[i] = dp[i] > dp[i - 1] ? dp[i] : dp[i - 1];
		}

		printf("%d\n", dp[n]);
	}

	return 0;
}