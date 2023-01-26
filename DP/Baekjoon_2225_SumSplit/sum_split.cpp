#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const int MOD = 1000000000;
int n, k;		// 1 <= n, k <= 200
int arr[201][201];

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	//for (int test_case = 1; test_case <= 1; test_case++)
	{
		scanf("%d %d", &n, &k);

		for (int i = 1; i <= n; i++)
		{
			arr[i][1] = 1;
			for (int j = 2; j <= k; j++)
			{
				arr[i][j] = i == 1 ? j : (arr[i - 1][j] + arr[i][j - 1]) % MOD;
			}
		}
	}

	printf("%d\n", arr[n][k]);

	return 0;
}