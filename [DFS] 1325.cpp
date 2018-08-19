#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<vector<int> > v(10000 + 1);

vector<int> ans;

bool visit[10000 + 1] = { false, };

int N = 0, M = 0;

int child[10000 + 1] = { 0, };

void DFS(int start, int index)
{
	visit[start] = true;

	for (int next : v[start])
	{
		if (!visit[next])
		{
			++child[index];

			DFS(next, index);
		}
	}
}

int main(void)
{
	int A = 0, B = 0;
	int MAX = 0;

	scanf("%d %d", &N, &M);

	while (M--)
	{
		scanf("%d %d", &A, &B);

		v[B].push_back(A);
	}

	for(int i=1; i<=N; i++)
	{ 
		memset(visit, false, sizeof(visit));	

		++child[i];

		DFS(i, i);

		MAX = max(MAX, child[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		if (child[i] == MAX)
		{
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());

	int vSize = ans.size();

	for (int i = 0; i < vSize; i++)
	{
		printf("%d ", ans[i]);
	}

	printf("\n");

	return 0;
}
