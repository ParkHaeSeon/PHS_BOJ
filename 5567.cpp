#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> v[10001], one, two;

bool visit[10001] = { false, };

int main(void)
{
	int n = 0, m = 0, a = 0, b = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);

		v[a].push_back(b);
		v[b].push_back(a);
	}

	visit[1] = true;

	for (auto next : v[1])
	{
		visit[next] = true;

		one.push_back(next);
	}

	for (auto vertex : one)
	{
		for (auto next : v[vertex])
		{
			if (visit[next]) continue;

			visit[next] = true;

			two.push_back(next);
		}
	}

	printf("답 = %d\n", one.size() + two.size());

	sort(one.begin(), one.end());
	sort(two.begin(), two.end());

	printf("초대 목록 : ");
	for (auto i : one) printf("%d ", i);
	printf("\n\ntwo : ");
	for (auto i : two) printf("%d ", i);
	
	printf("\n");

	return 0;
}