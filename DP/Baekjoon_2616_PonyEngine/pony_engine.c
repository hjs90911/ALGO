#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int guest_sum[50001];
int num_of_cars;
int dp[4][50001];

int max(int a, int b)
{
	return a > b ? a : b;
}

void input()
{
	scanf("%d", &n);

	int sum_of_guests = 0;
	for (int i = 1; i <= n; i++)
	{
		int num_of_guests;
		scanf("%d", &num_of_guests);
		sum_of_guests += num_of_guests;
		guest_sum[i] = sum_of_guests;
	}

	scanf("%d", &num_of_cars);
}

int main()
{
	freopen("input.txt", "r", stdin);

	input();

	for (int i = 1; i < 4; i++)
	{
		for (int j = i * num_of_cars; j <= n; j++)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - num_of_cars] + guest_sum[j] - guest_sum[j - num_of_cars]);
		}
	}

	printf("%d\n", dp[3][n]);

	return 0;
}