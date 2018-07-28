#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int N = 0; // 정점의 개수

int M = 0; // 간선의 개수

int V = 0; // 탐색을 시작할 정점의 번호

vector<vector<int> > adj;

queue<int> q;

int visit[1001] = { 0, };

void Add_adj(int s, int e)
{
	adj[s].push_back(e);
	adj[e].push_back(s);
}

void Sort_adj()
{
	for (int i = 1; i <= N; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}
}

void DFS(int start)
{
	printf("%d ", start);

	visit[start] = 1;

	for (int next : adj[start])
	{
		if(visit[next] == 0) DFS(next);
	}

	/*for (int i = 0; i< adj[start].size(); i++)
	{
		int next = adj[start][i];

		if (visit[next] == 0) DFS(next);
	}*/
}

void BFS(int start)
{
	q.push(start);

	while (!q.empty())
	{
		int qSize = q.size();

		for (int i = 0; i < qSize; i++)
		{
			int here = q.front();

			q.pop();

			if (visit[here] == 1) continue;

			visit[here] = 1;

			printf("%d ", here);
			
			for (int i = 0; i < adj[here].size(); i++)
			{
				q.push(adj[here][i]);
			}
		}
	}
	
	//while (N>0)
	//{
	//	for (int next : adj[start])
	//	{
	//		if (visit[next] == 0) // 방문 하지 않았다면,
	//		{
	//			printf("%d ", next);

	//			visit[next] = 1; // 방문처리 해주고

	//			q.push(next); // 큐에 담는다.
	//		}
	//	}

	//	if (!q.empty())
	//	{
	//		start = q.front();
	//		q.pop();
	//	}

	//	--N;
	//}
}

int main(void)
{
	int vs = 0, ve = 0;

	scanf("%d %d %d", &N, &M, &V);

	adj.resize(N + 1);

	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &vs, &ve);

		Add_adj(vs, ve);
	}
	
	Sort_adj();

	DFS(V);

	memset(visit, 0, sizeof(visit));

	printf("\n");

	BFS(V);

	printf("\n");

	return 0;
}
