#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MOD = 1000000;

int dp[5002] = { 0, };

string s;

int main(void)
{
	int len = 0;

	cin >> s;

	len = s.size();

	s = " " + s;

	dp[0] = 1;

	for (int i = 1; i <= len; i++)
	{
		int x = s[i] - '0';

		if ( 1 <= x && x <= 9)
		{
			dp[i] = (dp[i] + dp[i - 1]) % MOD;
		}

		if (i == 1) continue;

		if (s[i - 1] == '0') continue;

		int y = (s[i - 1] - '0') * 10 + (s[i] - '0');

		if ( 10 <= y && y <= 26)
		{
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}

	printf("%d\n", dp[len]);

	return 0;
}
