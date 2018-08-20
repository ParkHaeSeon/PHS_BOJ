#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

bool visit[100001] = { false, };

bool cycle[100001] = { false, };

int node[100001] = { 0, };

int T = 0;

int node_cnt = 0;

int ans = 0;

void DFS(int start)
{
	visit[start] = true;

	int next_vertex = node[start];

	if (!visit[next_vertex]) DFS(next_vertex);
	else
	{
		if (!cycle[next_vertex])
		{
			for (int x = next_vertex; start != x; x = node[x])
			{
				ans++;
				
				//printf("start : %d, x : %d, ans : %d\n", start, x, ans);
			}

			ans++;
		}
	}

	cycle[start] = true;
}

int main(void)
{

	scanf("%d", &T);

	while (T--)
	{
		memset(visit, false, sizeof(visit));
		memset(cycle, false, sizeof(cycle));
		ans = 0;

		scanf("%d", &node_cnt);

		for (int i = 1; i <= node_cnt; i++)
		{
			scanf("%d", &node[i]);
		}

		for (int i = 1; i <= node_cnt; i++)
		{
			if (visit[i]) continue;

			DFS(i);
		}

		printf("%d\n", node_cnt - ans);
	}

	return 0;
}
