#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

// http://jason9319.tistory.com/307

int V = 0, E = 0, Start = 0;

vector<vector<pair<int, int> > > vt;

int dist[20002] = { 0, };

int main(void)
{
	int u = 0, v = 0, w = 0;

	scanf("%d %d", &V, &E);

	scanf("%d", &Start);
	
	vt.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &u, &v, &w);

		vt[u].push_back({ v, w });
	}

	memset(dist, -1, sizeof(dist));

	priority_queue<pair<int, int> > pq; // (start 정점으로부터 도착 정점까지의 거리, 정점)

	pq.push({ 0,Start });

	while (!pq.empty())
	{
		int cost = -pq.top().first; // 거리(비용). '-'를 쓰는 이유는 pq를 최소 힙으로 사용하기 위함.
		int here = pq.top().second; // 현재 확인하는 정점

		pq.pop();

		if (dist[here] != -1) continue;

		dist[here] = cost; // 최단 거리 정보를 갱신

		for (auto it : vt[here])
		{
			int next = it.first;
			int next_cost = -it.second - cost; // 누적된 거리

			if (dist[next] != -1) continue;

			pq.push({ next_cost , next });
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == -1) printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}
