#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N = 0; // ����� ��

int num[301] = { 0, };

int dp[301] = { 0, };

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	dp[0] = num[0];

	dp[1] = num[0] + num[1];

	dp[2] = max(num[1] + num[2], num[0] + num[2]); 
	// ���� : num[0] + num[1]�� ������ �� �ȴ�. 
	// ������ ���� ����� ��ƾ���.

	for (int i = 3; i < N; i++)
	{
		dp[i] = max(dp[i-3] + num[i-1] + num[i], dp[i - 2] + num[i]);
	}

	printf("%d\n", dp[N - 1]);

	return 0;
}

/*
������ �� ����� ��� ��� : dp[i-3] + num[i-1] + num[i]

������ �� ����� ���� �ʴ� ��� : dp[i - 2] + num[i]
*/