#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int visit[100001] = { 0, };

int A = 0; // 스카이 콩콩
int B = 0; // 스카이 콩콩
int N = 0; // 동규 위치
int M = 0; // 주미 위치

queue<pair<int, int> > q;

int ans = 987654321;

int find()
{
	q.push(make_pair(N, 0));

	visit[N] = 1;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int qPos = q.front().first;
			int qCnt = q.front().second;

			q.pop();

			if (qPos == M)
			{
				return qCnt;
			}

			if (qPos - 1 >= 0 && visit[qPos - 1] == -1)
			{
				q.push(make_pair(qPos - 1, qCnt + 1));
				visit[qPos - 1] = 1;
			}

			if (qPos + 1 <= 100000 && visit[qPos + 1] == -1)
			{
				q.push(make_pair(qPos + 1, qCnt + 1));
				visit[qPos + 1] = 1;
			}

			if (qPos + A <= 100000 && visit[qPos + A] == -1)
			{
				q.push(make_pair(qPos + A, qCnt + 1));
				visit[qPos + A] = 1;
			}

			if (qPos - A >= 0 && visit[qPos - A] == -1)
			{
				q.push(make_pair(qPos - A, qCnt + 1));
				visit[qPos - A] = 1;
			}

			if (qPos + B <= 100000 && visit[qPos + B] == -1)
			{
				q.push(make_pair(qPos + B, qCnt + 1));
				visit[qPos + B] = 1;
			}

			if (qPos - B >= 0 && visit[qPos - B] == -1)
			{
				q.push(make_pair(qPos - B, qCnt + 1));
				visit[qPos - B] = 1;
			}

			if (qPos != 0 && qPos * A <= 100000 && visit[qPos * A] == -1)
			{
				q.push(make_pair(qPos * A, qCnt + 1));
				visit[qPos * A] = 1;
			}

			if (qPos != 0 && qPos * B <= 100000 && visit[qPos * B] == -1)
			{
				q.push(make_pair(qPos * B, qCnt + 1));
				visit[qPos * B] = 1;
			}
		}
	}
}

int main(void)
{
	memset(visit, -1, sizeof(visit));

	scanf("%d %d %d %d", &A, &B, &N, &M);

	printf("%d\n", find());

	return 0;
}
