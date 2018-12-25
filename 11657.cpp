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

#define INF 987654321

int N = 0, M = 0;

vector<pair<int, int> > v[501];

int dist[501] = { 0, };

int main(void)
{
	int A = 0, B = 0, C = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &A, &B, &C);

		v[A].push_back({ B, C });
	}

	fill(dist, dist + 501, INF);

	// 시작 정점
	dist[1] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int here = 1; here <= N; here++)
		{
			for (int index = 0; index < v[here].size(); index++)
			{
				int next = v[here].at(index).first;

				if (dist[next] > dist[here] + v[here].at(index).second)
				{
					if (i == N - 1)
					{
						// 음수 사이클

						printf("-1\n");

						return 0;
					}

					dist[next] = dist[here] + v[here].at(index).second;
				}
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == INF) printf("-1\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}