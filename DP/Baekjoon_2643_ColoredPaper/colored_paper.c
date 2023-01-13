#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int w;
	int l;
} Paper;

int n;			// 1 <= n <= 100
Paper p[101];
int dp[101];

int valid(Paper* p1, Paper* p2)
{
	if (p1->w <= p2->w && p1->l <= p2->l) return 1;
	else if (p1->w <= p2->l && p1->l <= p2->w) return 1;
	return 0;
}

int cmp(const void* v1, const void* v2)
{
	Paper* p1 = (Paper*)v1;
	Paper* p2 = (Paper*)v2;
	return p2->w * p2->l - p1->w * p1->l;
}

void input()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &p[i].w, &p[i].l);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	qsort(p + 1, n, sizeof(Paper), cmp);

	int max_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (valid(&p[i], &p[j]))
			{
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
			}
		}
		max_cnt = max_cnt > dp[i] ? max_cnt : dp[i];
	}

	printf("%d\n", max_cnt);

	return 0;
}