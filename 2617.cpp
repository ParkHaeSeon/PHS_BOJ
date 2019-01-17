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

vector<int> h[100], l[100];

int N = 0, M = 0;

bool visit[100] = { false, };

int cnt = 0;

void lDFS(int start)
{
	visit[start] = true;

	for (auto i : l[start])
	{
		if (!visit[i])
		{
			++cnt;

			lDFS(i);
		}
	}
}

void hDFS(int start)
{
	visit[start] = true;

	for (auto i : h[start])
	{
		if (!visit[i])
		{
			++cnt;

			hDFS(i);
		}
	}
}

int main(void)
{
	int s = 0, e = 0, result = 0;

	scanf("%d %d", &N, &M);

	while (M--)
	{
		scanf("%d %d", &s, &e);

		l[s].push_back(e); // s보다 가벼운 것들을 push_back
		h[e].push_back(s); // e보다 무거운 것들을 push_back
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visit, false, sizeof(visit));
		cnt = 0;

		hDFS(i);

		if (cnt >= (N + 1) / 2)
		{
			++result;
			continue;
		}

		memset(visit, false, sizeof(visit));
		cnt = 0;

		lDFS(i);

		if (cnt >= (N + 1) / 2) ++result;
	}

	printf("%d\n", result);

	return 0;
}