#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

const int MAX = 1000001;
int n, m;			// 2 <= n, m <= 1000000
std::vector<int> staff[MAX];
int praise[MAX];

void dfs(int node)
{
	for (int i = 0; i < staff[node].size(); i++)
	{
		int next = staff[node][i];
		praise[next] += praise[node];
		dfs(next);
	}
}

void input()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		int parent;
		scanf("%d", &parent);
		staff[parent].push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		praise[a] += b;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();

	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", praise[i]);
	}
	printf("\n");

	return 0;
}