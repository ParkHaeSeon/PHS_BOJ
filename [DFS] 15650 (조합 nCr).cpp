#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N = 0, M = 0;

bool used[10] = { false, };

vector<int> vc;

void DFS(int cnt)
{
	if (vc.size() == M)
	{
		for (auto i : vc)
		{
			printf("%d ", i);
		}

		printf("\n");

		return;
	}

	for (int i = cnt; i <= N; i++)
	{
		if (vc.size() < M)
		{
			vc.push_back(i);

			DFS(i + 1);

			vc.pop_back();
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	DFS(1);

	return 0;
}
