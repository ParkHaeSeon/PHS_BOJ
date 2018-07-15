#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

int T = 0; // test case
long long score[3][100001] = { 0, };
long long dp[100001][3] = { 0, };

using namespace std;

int main(void)
{
	int n = 0;
	long long sum = 0;

	scanf("%d", &T);

	while (T > 0)
	{
		scanf("%d", &n);

		for (int i = 1; i <= 2; i++)
		{
			for(int j=1; j<=n; j++)
			{ 
				scanf("%lld", &score[i][j]);
			}
		}

		dp[0][0] = dp[0][1] = dp[0][2] = 0;

		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])); // ¾È ¶âÀ½
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + score[1][i]; // À§ ¶âÀ½
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + score[2][i];// ¾Æ·¡ ¶âÀ½
		}
	
		for (int i = 1; i <= n; i++)
		{
			sum = max(dp[i][0], max(dp[i][1], dp[i][2]));
		}

		printf("%lld\n", sum);

		sum = 0;

		--T;
	}

	return 0;
}