#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N = 0; // 수빈이 위치
int K = 0; // 동생의 위치

queue<pair<int, int> > q;

int trace[200002] = { 0, };

int find(int start, int end)
{
	int pos = 0, cnt = 0;

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

			if (pos - 1 >= 0 && trace[pos - 1] == -1)
			{
				q.push(make_pair(pos - 1, cnt + 1));

				trace[pos - 1] = pos;
			}

			if (pos + 1 <= 100000 && trace[pos + 1] == -1)
			{
				q.push(make_pair(pos + 1, cnt + 1));

				trace[pos + 1] = pos;
			}

			if (2 * pos <= 100000 && trace[2 * pos] == -1)
			{
				q.push(make_pair(2 * pos, cnt + 1));

				trace[2 * pos] = pos;
			}
		}
	}
}

int main(void)
{
	vector<int> v;

	scanf("%d %d", &N, &K);

	memset(trace, -1, sizeof(trace));

	printf("%d\n", find(N, K));

	int index = K;

	int end = K;

	while (end != N)
	{
		v.push_back(trace[end]);

		end = trace[end];
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		printf("%d ", v[i]);
	}

	printf("%d\n", K);

	return 0;
}