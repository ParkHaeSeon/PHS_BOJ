#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<vector<int> > v;
vector<vector<int> > t;

int N = 0;

int num[10001] = { 0, };

void Tree(int start) // 단일
{
	queue<int> q;

	bool visit[10001] = { false, };

	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int here = q.front();

			q.pop();

			visit[here] = true;

			for (auto i : v[here])
			{
				if (!visit[i])
				{
					t[here].push_back(i);
					q.push(i);
				}
			}
		}
	}
}

long long answer(int here, int cur)
{
	long long ret = 0;

	for (auto next : t[here])
	{
		if (cur == 0) // 우수 마을이 아니라면
		{
			ret += max(answer(next, 0), num[next] + answer(next, 1));
		}
		else if (cur == 1) // 우수 마을이라면
		{
			ret += answer(next, 0);
		}
	}

	return ret;
}

int main(void)
{
	int s = 0, e = 0;

	scanf("%d", &N);

	v.resize(N + 1);
	t.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);
	}

	int var = N - 1;

	while (var--)
	{
		scanf("%d %d", &s, &e);

		v[s].push_back(e);
		v[e].push_back(s);
	}

	Tree(1);

	printf("%lld\n", max(answer(1, 0), num[1] + answer(1, 1)));

	return 0;
}
