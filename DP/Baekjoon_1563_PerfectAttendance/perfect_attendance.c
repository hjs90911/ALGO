#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int dp[1001][2][3];

int countAttandence(int day, int late, int abs)
{
	if (late == 2 || abs == 3)
		return 0;
	if (day > n)
		return 1;

	if (dp[day][late][abs] != -1)
		return dp[day][late][abs];

	dp[day][late][abs] = (countAttandence(day + 1, late, 0) + 
		countAttandence(day + 1, late + 1, 0) + countAttandence(day + 1, late, abs + 1)) % 1000000;

	return dp[day][late][abs];
}

void input()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	printf("%d\n", countAttandence(1, 0, 0));

	return 0;
}