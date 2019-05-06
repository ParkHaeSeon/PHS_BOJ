#include <iostream>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <unordered_map>  
#include <unordered_set>  
#include <tuple>
#include <sstream>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")

using namespace std;

int dp[301][301] = { 0, };

int main(void)
{
	int n = 0, m = 0;

	scanf("%d %d", &n, &m);

	string sn, sm;

	cin >> sn >> sm;

	for (int i = 1; i <= sn.length(); i++) dp[i][0] = 2e9;
	for (int j = 1; j <= sm.length(); j++) dp[0][j] = 2e9;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = abs(sn.at(i - 1) - sm.at(j - 1));
			dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
		}

	printf("%d\n", dp[n][m]);

	return 0;
}