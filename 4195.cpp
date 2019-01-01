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

int F = 0;

pair<int, int> parent[200002];
// first = 부모 노드 번호
// second = 자신을 포함한 자식 노드의 개수

int level[200002];

int Find(int u)
{
	// 루트 노드이면 return
	if (u == parent[u].first) return u;

	// 그게 아니라면, 자신의 루트 노드를 향해 찾아 가면서, 갱신한다.
	return parent[u].first = Find(parent[u].first);
}

void merge(int u, int v)
{
	u = Find(u);
	v = Find(v);

	// 루트가 같으면, 이미 같은 트리(집합)이라는 것이다.
	if (u == v)
	{
		printf("%d\n", parent[v].second);
		return;
	}

	// u가 v보다 더 깊은 트리라면 swap.
	if (level[u] > level[v])
	{
		// 항상 u가 더 작은 트리가 되도록 한다.
		swap(u, v);
	}

	// (u는 더 작은 트리의 '루트 노드' 였다.) u의 루트를 v로 바꿔준다.
	parent[u].first = v;

	// u와 v의 깊이가 같을 때, v의 깊이를 늘려준다.
	if (level[u] == level[v]) ++level[v];

	// 루트 노드에는 항상 아래 노드의 총 합 개수를 저장해준다.
	parent[v].second += parent[u].second;

	printf("%d\n", parent[v].second);
}

int main(void)
{
	int cnt = 1, T = 0;

	char s[21], e[21];

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &F);

		map<string, int> name;

		int num = 1;

		for (int i = 0; i < F; i++)
		{
			scanf("%s %s", s, e);

			if (name[s] == 0)
			{
				parent[num].first = num;
				parent[num].second = 1;

				level[num] = 1;

				name[s] = num++;
			}

			if (name[e] == 0)
			{
				parent[num].first = num;
				parent[num].second = 1;

				level[num] = 1;

				name[e] = num++;
			}

			merge(name[s], name[e]);
		}
	}

	return 0;
}