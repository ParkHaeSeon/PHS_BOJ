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
// first = �θ� ��� ��ȣ
// second = �ڽ��� ������ �ڽ� ����� ����

int level[200002];

int Find(int u)
{
	// ��Ʈ ����̸� return
	if (u == parent[u].first) return u;

	// �װ� �ƴ϶��, �ڽ��� ��Ʈ ��带 ���� ã�� ���鼭, �����Ѵ�.
	return parent[u].first = Find(parent[u].first);
}

void merge(int u, int v)
{
	u = Find(u);
	v = Find(v);

	// ��Ʈ�� ������, �̹� ���� Ʈ��(����)�̶�� ���̴�.
	if (u == v)
	{
		printf("%d\n", parent[v].second);
		return;
	}

	// u�� v���� �� ���� Ʈ����� swap.
	if (level[u] > level[v])
	{
		// �׻� u�� �� ���� Ʈ���� �ǵ��� �Ѵ�.
		swap(u, v);
	}

	// (u�� �� ���� Ʈ���� '��Ʈ ���' ����.) u�� ��Ʈ�� v�� �ٲ��ش�.
	parent[u].first = v;

	// u�� v�� ���̰� ���� ��, v�� ���̸� �÷��ش�.
	if (level[u] == level[v]) ++level[v];

	// ��Ʈ ��忡�� �׻� �Ʒ� ����� �� �� ������ �������ش�.
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