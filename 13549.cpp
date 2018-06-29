#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

int Cnt = 0;
int MAX = 7654321;

queue<pair<int, int>> q;

int v[100001] = { 0, };

int find(int N, int K)
{
	if (N >= K)
	{
		return N - K;
	}

	q.push(make_pair(N, 0));
	v[N] = 1;

	int qData = 0, qCnt = 0, qSzie = 0;

	while (!q.empty())
	{
			qData = q.front().first;
			qCnt = q.front().second;

			q.pop();

			v[qData] = 1;

			if (qData == K)
			{
				MAX = min(MAX, qCnt);
			}

			if (qData - 1 >= 0 && !v[qData - 1])
			{
				q.push(make_pair(qData - 1, qCnt + 1));
			}

			if (qData + 1 < 100001 && !v[qData + 1])
			{
				q.push(make_pair(qData + 1, qCnt + 1));
			}

			if (qData * 2 < 100001 && !v[qData * 2])
			{
				q.push(make_pair(qData * 2, qCnt));
			}
	}

	return MAX;
}

int main(void)
{
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d\n", find(N, K));

	//printf("%d\n", Cnt);
	
	return 0;
}