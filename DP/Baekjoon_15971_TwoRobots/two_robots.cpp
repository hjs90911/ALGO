#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

bool finished = false;
int n;			// 1 <= n <= 100000
int robot1, robot2;
std::vector<std::pair<int, int>> v[100001];
bool visited[100001];
int ans, min_len;

void dfs(int idx, int sum, int max_len)
{
	if (finished) return;
	if (idx == robot2)
	{
		finished = true;
		printf("%d\n", sum - max_len);
		return;
	}

	visited[idx] = true;

	for (auto& p : v[idx])
	{
		int next_room = p.first;
		int next_len = p.second;
		if (visited[next_room]) continue;
		dfs(next_room, sum + next_len, std::max(max_len, next_len));
	}
}

void input()
{
	scanf("%d %d %d", &n, &robot1, &robot2);

	for (int i = 0; i < n; i++)
	{
		int front, rear, length;
		scanf("%d %d %d", &front, &rear, &length);
		v[front].push_back({ rear, length });
		v[rear].push_back({ front, length });
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	//for (int test_case = 1; test_case <= 1; test_case++)
	{
		input();
		dfs(robot1, 0, 0);
	}

	return 0;
}