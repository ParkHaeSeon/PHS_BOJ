#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int num = 0;

int lotto[50] = { 0, };

void DFS(int pos, vector<int> vc, int cnt)
{
	if (cnt == 6)
	{
		for (auto k : vc)
		{
			printf("%d ", k);
		}

		printf("\n");

		return;
	}


	for (int i = pos; i < num; i++)
	{
		vc.push_back(lotto[i]);
		DFS(i + 1, vc, cnt + 1);
		vc.pop_back();
	}
}

int main(void)
{

	while (1)
	{
		scanf("%d", &num);

		if (num == 0) break;

		for (int i = 0; i < num; i++)
		{
			scanf("%d", &lotto[i]);
		}

		vector<int> v;

		DFS(0, v, 0);

		printf("\n");
	}

	return 0;
}