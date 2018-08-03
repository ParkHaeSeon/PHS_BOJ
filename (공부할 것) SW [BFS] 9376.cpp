#include <iostream>
#include <deque>
#include <cstdio>
#include <vector>

#define INF 987654321

using namespace std;

char map[102][102];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void BFS(pair<int, int> p, int d[102][102], int h, int w)
{
	deque<pair<int, int> > dq;

	d[p.first][p.second] = 0;

	dq.push_back(p);


	while (!dq.empty())
	{
		p = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int py = p.first + dy[i];
			int px = p.second + dx[i];

			if (py <= -1 || px <= -1 || py > h + 1 || px > w + 1 || map[py][px] == '*') continue;

			if (d[py][px] == INF)
			{
				if (map[py][px] == '#')
				{
					dq.push_back(make_pair(py, px));
					d[py][px] = d[p.first][p.second] + 1;
				}
				else
				{
					d[py][px] = d[p.first][p.second];
					dq.push_front(make_pair(py, px));
				}
			}
		}
	}
}

int main(void)
{
	int testcase = 0;
	int d1[102][102] = { 0, };
	int d2[2][102][102] = { 0, };

	scanf("%d", &testcase);

	while (testcase--)
	{
		int h = 0, w = 0, k = 0;

		scanf("%d %d", &h, &w);

		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
				{
					map[i][j] = 0;
				}
				else
				{
					cin >> map[i][j];
					// not scanf("%1c", &map[i][j]);
				}
			}
		}
;
		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				d1[i][j] = INF;
				d2[0][i][j] = INF;
				d2[1][i][j] = INF;
			}
		}

		BFS(make_pair(0, 0), d1, h, w);

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (map[i][j] == '$')
				{
					BFS(make_pair(i, j), d2[k++], h, w);
				}
			}
		}

		int MIN = INF;

		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				int sum = 0;

				if (map[i][j] != '*')
				{
					sum += d1[i][j] + d2[0][i][j] + d2[1][i][j];

					if (map[i][j] == '#')
					{
						sum -= 2;
					}

					if (MIN > sum) MIN = sum;
				}
			}
		}

		printf("%d\n", MIN);
	}

	return 0;
}