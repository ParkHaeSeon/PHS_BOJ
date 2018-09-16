#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

bool prime[10000] = { false, };
bool num[10000] = { false, };

void getPrime()
{
	for (int i = 2; i <= 9999; i++)
	{
		if (num[i]) continue;

		prime[i] = true; // 소수 O

		for (int j = 2 * i; j <= 9999; j += i)
		{
			num[j] = true; // 소수 X
		}
	}

	for (int i = 0; i <= 999; i++)
	{
		prime[i] = false;
	}
}

int BFS(int s, int e)
{
	queue<int> q;

	bool visit[10000] = { false, };

	q.push(s);

	int ret = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int here = q.front();

			q.pop();

			if (here == e) return ret;

			for (int i = 0; i <= 9; i++)
			{
				int thousand = here / 1000;
				int hundred = (here % 1000) / 100;
				int ten = (here % 100) / 10;
				int one = here % 10;

				if (i != thousand && i != 0)
				{
					int next = here - (thousand * 1000) + i * 1000;

					if (!visit[next] && prime[next]) // 방문하지 않았고, 소수라면 
					{
						visit[next] = true;
						q.push(next);
					}
				}

				if (i != hundred)
				{
					int next = here - (hundred * 100) + i * 100;

					if (!visit[next] && prime[next])
					{
						visit[next] = true;
						q.push(next);
					}
				}

				if (i != ten)
				{
					int next = here - (ten * 10) + i * 10;

					if (!visit[next] && prime[next])
					{
						visit[next] = true;

						q.push(next);
					}
				}

				if (i != one)
				{
					int next = here - one + i;

					if (!visit[next] && prime[next])
					{
						visit[next] = true;

						q.push(next);
					}
				}
			}
		}

		++ret;
	}

	return -1;
}

int main(void)
{
	int T = 0, s = 0, e = 0;

	getPrime();

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &s, &e);

		int ans = BFS(s, e);

		if (ans == -1) printf("Impossible\n");
		else printf("%d\n", ans);
	}

	return 0;
}
