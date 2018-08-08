#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

bool used[9] = { false, };

int N = 0, M = 0;

vector<int> v;

void DFS()
{
	if (v.size() == M)
	{
		for (auto i : v)
		{
			printf("%d ", i);
		}

		printf("\n");

		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!used[i])
		{
			used[i] = true;
			v.push_back(i);
			DFS();
			used[i] = false;
			v.pop_back();
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	DFS();

	return 0;
}
