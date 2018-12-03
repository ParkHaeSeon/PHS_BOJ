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

vector<int> v[1001];

bool visit[1001] = { false, };

int connect = 0;

void DFS(int start)
{
	visit[start] = true;

	for (auto next : v[start])
	{
		if (!visit[next]) DFS(next);
	}
}

int main(void)
{
	int T = 0, cnt = 0, n = 0;

	scanf("%d", &T);

	while (T--)
	{
		connect = 0;
		memset(visit, false, sizeof(visit));

		scanf("%d", &cnt);

		for (int i = 1; i <= cnt; i++)
		{
			scanf("%d", &n);

			v[i].push_back(n);
		}

		for (int i = 1; i <= cnt; i++)
		{
			if (!visit[i])
			{
				++connect;
				DFS(i);
			}
		}

		for (int i = 1; i <= cnt; i++)
		{
			if (!v[i].empty()) v[i].clear();
		}

		printf("%d\n", connect);
	}

	return 0;
}