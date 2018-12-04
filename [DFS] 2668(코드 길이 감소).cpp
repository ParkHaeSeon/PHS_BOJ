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

vector<int> v[101];
vector<int> ans;

int N = 0, start = 0;

bool stop = false;
bool visit[101] = { false, };

void DFS(int s)
{
	// Cycle을 찾았으면(stop이 true일 때), 그냥 바로 return.
	if (stop) return;

	visit[s] = true;

	for (auto i : v[s])
	{
		if (start == i)
		{
			/*
			결국 ans vector에 push_back 되는 것은
			Cycle 되는 모든 정점들이다.

			예) 
			1 → 3 → 1 일 때, 1 저장
			3 → 1 → 3 일 때, 3 저장
			4 → 5 → 5 일 때, 저장 안 한다.(start가 4이고, i는 5이기 때문이다.)
			5 → 5 일 때, 저장(start == 5 == i)
			*/

			ans.push_back(i);
			stop = true;
			return;
		}

		if(!visit[i]) DFS(i);
	}
}

int main(void)
{
	int n = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &n);
		v[i].push_back(n);
	}

	for (int i = 1; i <= N; i++)
	{
		start = i;
		stop = false;

		/*
		여기에서 visit를 false로 초기화 해줘야한다.
		모든 정점에 대하여 Cycle을 검사해야 하기 때문이다.
		*/

		memset(visit, false, sizeof(visit));

		DFS(i);	
	}

	sort(ans.begin(), ans.end());

	printf("%d\n", ans.size());

	for (auto i : ans)
	{
		printf("%d\n", i);
	}

	return 0;
}
