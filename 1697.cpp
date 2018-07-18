#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N = 0; // 수빈이 위치
int K = 0; // 동생의 위치

queue<pair<int, int> > q; // 위치 저장 및 시간(초) 저장

int visit[100001] = { 0, };

int find(int start, int end)
{
	int pos = 0, cnt = 0;

	visit[start] = 1;

	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++)
		{
			pos = q.front().first;
			cnt = q.front().second;

			q.pop();

			if (pos == K)
			{
				return cnt;
			}

			if (pos - 1 >= 0 && visit[pos - 1] == 0)
			{
				q.push(make_pair(pos - 1, cnt + 1));

				visit[pos - 1] = 1;
			}

			if (pos + 1 <= 100000 && visit[pos + 1] == 0)
			{
				q.push(make_pair(pos + 1, cnt + 1));

				visit[pos + 1] = 1;
			}

			if (2 * pos <= 100000 && visit[2 * pos] == 0)
			{
				q.push(make_pair(2 * pos, cnt + 1));

				visit[2 * pos] = 1;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &K);

	printf("%d\n", find(N, K));

	return 0;
}
