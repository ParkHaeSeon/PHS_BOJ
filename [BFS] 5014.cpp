#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int F = 0; // 건물의 총 F층
int S = 0; // 지금 있는 층 S
int G = 0; // 목적지 층
int U = 0; // 위로 U만큼 이동
int D = 0; // 아래로 D만큼 이동

int visit[1000001] = { 0, };

/*
10 1 10 2 1 → 6
예제 1 설명 : 건물은 총 10층이고, 지금 있는 층은 1층이다. 
그리고 목적지는 10층이고, 엘레베이터는 위로 2층, 아래로 1층 만큼 이동할 수 있다.
1 -> 3 -> 5 -> 7 -> 9 -> 8 -> 10
*/

queue<pair<int, int> > q;

int BFS()
{
	q.push(make_pair(S, 0));

	visit[S] = 1;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int here = q.front().first;
			int cnt = q.front().second;

			q.pop();

			if (here == G)
			{
				return cnt;
			}

			if (here + U <= 1000000 && visit[here + U] == -1)
			{
				q.push(make_pair(here + U, cnt + 1));
				visit[here + U] = 1;
			}

			if (here - D >= 1 && visit[here - D] == -1)
			{
				q.push(make_pair(here - D, cnt + 1));
				visit[here - D] = 1;
			}
		}
	}

	return -1;
}

int main(void)
{
	memset(visit, -1, sizeof(visit));

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	int ans = BFS();

	if (ans == -1) printf("use the stairs\n");
	else printf("%d\n", ans);

	return 0;
}