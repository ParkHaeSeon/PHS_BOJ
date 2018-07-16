#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int> > adj; 

bool visit[1001] = { false, };

int N = 0, M = 0; // N : 정점 개수, M : 간선 개수

int Connected_Component = 1; // 연결 요소의 개수

void addEdge(int s, int e) // 간선 추가 함수
{
	adj[s].push_back(e);
	adj[e].push_back(s);
}

void sortVector()
{
	for (int j = 1; j <= N; j++)
	{
		sort(adj[j].begin(), adj[j].end());
	}
}

void DFS(int start)
{
	visit[start] = true;

	for (int next : adj[start])
	{
		if (!visit[next]) DFS(next);
	}
}

void DFS_search()
{
	for (int a = 1; a <= N; a++)
	{
		if (!visit[a])
		{
			DFS(a);
			++Connected_Component;
		}
	}
}

int main()
{
	int vs = 0, ve = 0; // vs : 간선 시작점, ve : 간선 끝점

	scanf("%d %d", &N, &M);

	adj.resize(N+1);

	for (int i = 0; i < M; i++) // 간선 추가
	{
		scanf("%d %d", &vs, &ve);

		addEdge(vs, ve);
	}

	sortVector();

	DFS(1);

	DFS_search();

	printf("%d\n", Connected_Component);
	
	return 0;
}
