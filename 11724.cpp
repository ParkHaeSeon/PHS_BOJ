// 2018�� ��ݱ� �Ｚ SDS SW ���� �׽�Ʈ ���⹮�� 
// ���� 15683�� ����

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int> > adj; 

bool visit[1001] = { false, };

int N = 0, M = 0; // N : ���� ����, M : ���� ����

int Connected_Component = 1; // ���� ����� ����

void addEdge(int s, int e) // ���� �߰� �Լ�
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
	int vs = 0, ve = 0; // vs : ���� ������, ve : ���� ����

	scanf("%d %d", &N, &M);

	adj.resize(N+1);

	for (int i = 0; i < M; i++) // ���� �߰�
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