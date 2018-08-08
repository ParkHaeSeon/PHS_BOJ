#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N = 0, M = 0;

int num[51][51] = { 0, };

int main(void)
{
	int ss = 1;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &num[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int len = 1; len < min(N, M); len++)
			{
				if (i + len >= N || j + len >= M) continue;

				if ((num[i][j] == num[i + len][j]) && (num[i + len][j] == num[i][j + len]) && (num[i][j + len] == num[i + len][j + len]))
				{
					ss = max(ss, (len+1)*(len+1));
				}
			}
		}
	}

	printf("%d\n", ss);

	return 0;
}