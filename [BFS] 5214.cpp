#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

#define Hyper 100000

using namespace std;

int N = 0, K = 0, M = 0;

/*
N : 역의 수
K : 하이퍼튜브가 서로 연결하는 역의 개수
M : 하이퍼튜브의 개수
*/

vector< vector<int> > v(102002);

bool visit[102002] = { false, };

queue<pair<int, int> > q;

int BFS(int start)
{
	q.push({ start, 0 });

	visit[start] = true;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int here = q.front().first;
			int cnt = q.front().second;

			q.pop();

			if (here == N)
			{
				return cnt;
			}

			for (int next : v[here])
			{
				if (!visit[next])
				{
					visit[next] = true;
					q.push({ next, cnt + 1 });
				}
			}
		}
	}

	return -1;
}

void createHyertube(int H, int node)
{
	v[H].push_back(node);
	v[node].push_back(H);

	/*
	쓰면 '시간 초과' 발생!
	C++의 STL sort()는 퀵소트 = O(nlogn)
	sort(v[H].begin(), v[H].end());
	sort(v[node].begin(), v[node].end());
	*/
}

int main(void)
{
	int input_connection = 0, pos = 1;

	scanf("%d %d %d", &N, &K, &M);

	while (M--)
	{
		for (int i = 0; i < K; i++)
		{
			scanf("%d", &input_connection);

			createHyertube(Hyper + pos, input_connection);

			// Hypertube start 100001, end 100000 + M
		}

		++pos;
	}

	int result = BFS(1);

	if (result == -1) printf("-1\n");
	else printf("%d\n", result / 2 + 1);

	return 0;
}