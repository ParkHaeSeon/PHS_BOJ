#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

// https://www.acmicpc.net/problem/2668

// 결국 문제가 원하는 것은 싸이클(Cycle)이다.

int N = 0;

vector<int> node;

vector<int> ans;

bool visit[101] = { false, };
bool cycle[101] = { false, };

bool DFS(int startNum, int nodeNum)
{
	if (visit[nodeNum]) return false;

	visit[nodeNum] = true;

	if (startNum == nodeNum || DFS(startNum, node[nodeNum]))
	{
		ans.push_back(nodeNum);
		cycle[nodeNum] = true;
		return true;
	}

	return false;
}

int main(void)
{
	scanf("%d", &N);

	node.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &node[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			visit[j] = cycle[j];
		}

		DFS(i, node[i]);
	}

	cout << ans.size() << '\n';

	sort(ans.begin(), ans.end());

	int len = ans.size();

	for (int i = 0; i < len; i++)
	{
		printf("%d\n", ans[i]);
	}

	return 0;
}
