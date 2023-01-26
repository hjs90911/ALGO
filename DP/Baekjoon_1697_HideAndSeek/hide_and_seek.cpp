#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

const int MAX_VALUE = 100001;
int n, k;	// 0 <= n, k <= 100000
int t[MAX_VALUE];

void move()
{
	int w[3];
	std::queue<int> q;
	t[n] = 0;
	q.push(n);

	while (!q.empty())
	{
		int x = q.front();
		int time = t[x];
		if (x == k) break;
		w[0] = x - 1;
		w[1] = x * 2;
		w[2] = x + 1;

		for (int i = 0; i < 3; i++)
		{
			int nx = w[i];
			int nt = time + 1;

			if (nx < 0 || nx >= MAX_VALUE) continue;
			if (t[nx] < nt) continue;
			t[nx] = nt;
			q.push(nx);
		}

		q.pop();
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &k);

	for (int i = 0; i < MAX_VALUE; i++)
	{
		t[i] = MAX_VALUE;
	}

	move();
	printf("%d\n", t[k]);

	return 0;
}