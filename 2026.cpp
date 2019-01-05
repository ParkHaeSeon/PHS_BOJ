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

// 총 N명의 학생 중, K명을 소풍 보내려고 한다.

int K = 0, N = 0, F = 0;

bool Friends[901][901];

bool student[901] = { false, };

bool visit[901] = { false, };

bool stop = false;

vector<int> v;

int start = 0;

void backtracking(int start)
{
	if (stop) return;

	visit[start] = true; // 아래 if문보다 먼저
	v.push_back(start); // 아래 if문보다 먼저

	if (K == v.size())
	{
		stop = true;

		for (auto i : v) printf("%d\n", i);

		return;
	}

	for (int i = start + 1; i <= N; i++)
	{
		if (visit[i]) continue;

		bool isFriend = true;

		for (auto next : v)
		{
			if (!Friends[i][next])
			{
				isFriend = false;
				break;
			}
		}

		if (isFriend) backtracking(i);
	}
}

int main(void)
{
	int s = 0, e = 0;

	scanf("%d %d %d", &K, &N, &F);

	for (int i = 0; i < F; i++)
	{
		scanf("%d %d", &s, &e);

		Friends[s][e] = true;
		Friends[e][s] = true;
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visit, false, sizeof(visit));

		if (!v.empty()) v.clear();

		backtracking(i);

		if (stop) break;
	}

	if (!stop) printf("-1\n");

	return 0;
}
