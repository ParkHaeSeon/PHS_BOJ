#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int num[3][100001] = { 0, };

int dp[3][100001] = { 0, };
// dp[0~2][n] -> 1 : 위 선택, 2 : 아래 선택, 0 : 선택 X
// dp[i][j] -> i 상태에 따른 최대 점수(i는 3가지 경우의 수), j는 i 행에 따른 선택한 열

int main(void)
{
	int T = 0; // test case
	int n = 0;

	scanf("%d", &T);

	while (T > 0)
	{
		scanf("%d", &n);

		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &num[i][j]);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			dp[0][i] = max(dp[0][i-1], max(dp[1][i-1], dp[2][i-1]));
			dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + num[1][i];
			dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + num[2][i];
		}

		printf("%d\n", max(max(dp[0][n], dp[1][n]), dp[2][n]));

		memset(num, 0, sizeof(num));
		memset(dp, 0, sizeof(dp));

		n = 0;

		--T;
	}

	return 0;
}




/*
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
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + score[1][i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + score[2][i];
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

*/
