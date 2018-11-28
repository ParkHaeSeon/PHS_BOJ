#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first < b.first;
}

int main(void)
{
	int A = 0, B = 0, N = 0, MAX = 0;

	int dp[501] = { 0, };

	memset(dp, 0, sizeof(dp));

	vector<pair<int, int> > v;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &A, &B);

		v.push_back({ A,B });
	}

	sort(v.begin(), v.end(), cmp);

	// sort(v.begin(), v.end()); ��� �ᵵ �ȴ�.
	// default�� first �������� �������� ����

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (v.at(i).second > v.at(j).second && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}

		MAX = max(MAX, dp[i]);
	}

	MAX = N - MAX;

	printf("%d\n", MAX);

	return 0;
}