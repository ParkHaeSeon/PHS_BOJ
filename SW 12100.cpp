#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N = 0;

vector<vector<int> > map;

int BruteForce_BFS()
{
	queue<vector<vector<int> > > q;

	q.push(map);

	int ret = 0, c = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			
			vector<vector<int> > v = q.front();

			vector<vector<int> > visit(N+1);

			q.pop();

			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					ret = max(ret, v[i][j]);
				}
			}

			// UP
			for (int i = 1; i <= N; i++)
			{
				visit[i].assign(N+1, 0);
			}

			vector<vector<int> > up = v;

			for (int i = 2; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					int ny = i;

					while (ny - 1>= 1 && up[ny-1][j] == 0)
					{
						ny--;
					}

					if (ny - 1 >= 1 && up[ny - 1][j] == up[i][j] && visit[ny-1][j] == 0)
					{
						up[ny - 1][j] = up[i][j] * 2;
						up[i][j] = 0;
						visit[ny - 1][j] = 1;
					}
					else
					{
						swap(up[ny][j], up[i][j]);
					}
				}
			}

			// DOWN
			for (int i = 1; i <= N; i++)
			{
				visit[i].assign(N + 1, 0);
			}

			vector<vector<int> > down = v;

			for (int i = N-1; i >= 1; i--)
			{
				for (int j = 1; j <= N; j++)
				{
					int ny = i;

					while (ny + 1 <= N && up[ny + 1][j] == 0)
					{
						ny++;
					}

					if (ny + 1 <= N && down[ny + 1][j] == down[i][j] && visit[ny + 1][j] == 0)
					{
						down[ny + 1][j] = down[i][j] * 2;
						down[i][j] = 0;
						visit[ny + 1][j] = 1;
					}
					else
					{
						swap(down[ny][j], down[i][j]);
					}
				}
			}

			// LEFT
			for (int i = 1; i <= N; i++)
			{
				visit[i].assign(N + 1, 0);
			}

			vector<vector<int> > left = v;

			for (int i = 1; i <= N; i++)
			{
				for (int j = 2; j <= N; j++)
				{
					int nx = j;

					while (nx - 1 >= 1 && left[i][nx-1] == 0)
					{
						nx--;
					}

					if (nx - 1 >= 1 && left[i][nx-1] == left[i][j] && visit[i][nx-1] == 0)
					{
						left[i][nx-1] = left[i][j] * 2;
						left[i][j] = 0;
						visit[i][nx-1] = 1;
					}
					else
					{
						swap(left[i][nx], left[i][j]);
					}
				}
			}


			// RIGHT
			for (int i = 1; i <= N; i++)
			{
				visit[i].assign(N + 1, 0);
			}

			vector<vector<int> > right = v;

			for (int i = 1; i <= N; i++)
			{
				for (int j = N-1; j >= 1; j--)
				{
					int nx = j;

					while (nx + 1 <= N && right[i][nx + 1] == 0)
					{
						nx++;
					}

					if (nx + 1 <= N && right[i][nx + 1] == right[i][j] && visit[i][nx + 1] == 0)
					{
						right[i][nx + 1] = right[i][j] * 2;
						right[i][j] = 0;
						visit[i][nx + 1] = 1;
					}
					else
					{
						swap(right[i][nx], right[i][j]);
					}
				}
			}

			q.push(up);
			q.push(down);
			q.push(left);
			q.push(right);
		}

		if (c == 5) break;

		c++;
	}

	return ret;
}

int main(void)
{
	int x = 0;

	scanf("%d", &N);

	map.resize(N + 1);

	for (int i = 1; i <= N; i++) // 세로 y
	{
		for (int j = 1; j <= N; j++) // 가로 x
		{
			scanf("%d", &x);

			map[i].push_back(x);
		}
	}

	printf("%d\n", BruteForce_BFS());

	return 0;
}