#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int h = 0; // row
int w = 0; // column
int door = 0;
int person_num = 0;
int visit[101][101][2] = { 0, };
int d[101][101] = { 0, }; // door position get bool
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int p1y = 0, p1x = 0;
int p2y = 0, p2x = 0;

char map[101][101];

queue< pair< pair<int, int>, int > > q;

bool p1 = false;
bool p2 = false;

void init()
{
	door = 0;

	person_num = 0;

	memset(visit, -1, sizeof(visit));

	memset(d, -1, sizeof(d));

	while (!q.empty())
	{
		q.pop();
	}
}

void near(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{

		int R = r + dy[i];
		int C = c + dx[i];

		if (R < 0 || C < 0 || R >= h || C >= w) continue;

		if (map[R][C] == '#') --door;
	}
}

void BFS()
{
	visit[p1y][p1x][0] = 1;
	visit[p2y][p2x][1] = 1;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int s = q.front().second;

			q.pop();

			if (map[y][x] == '@')
			{
				if (s == 0)
				{
					//near(y, x);

					if (p2) return;

					p1 = true;
				}

				else if (s == 1)
				{
					//near(y, x);

					if (p1) return;

					p2 = true;
				}
			}

			for (int i = 0; i < 4; i++)
			{
				int Y = y + dy[i];
				int X = x + dx[i];

				if (Y < 0 || X < 0 || Y >= h || X >= w || map[Y][X] == '*' || visit[Y][X][s] == 1) continue;

				if (s == 0) // prisoner 1st
				{
					if ((map[Y][X] == '#' || map[Y][X] == '@' || map[Y][X] == '.') && visit[Y][X][s] == -1)
					{
						q.push(make_pair(make_pair(Y, X), s));
						visit[Y][X][s] = 1;
					}
				}

				if (s == 1) // prisoner 2nd
				{
					if ((map[Y][X] == '#' || map[Y][X] == '@' || map[Y][X] == '.') && visit[Y][X][s] == -1)
					{
						q.push(make_pair(make_pair(Y, X), s));
						visit[Y][X][s] = 1;
					}
				}

				if (map[Y][X] == '#' || map[Y][X] == '@')
				{
					if (d[Y][X] == -1) ++door;

					d[Y][X] = 1;
				}
			}	
		}
	}
}

void changeDoor()
{
	for (int i = 0; i < w; i++)
	{
		if (map[0][i] == '#')
		{
			map[0][i] = '@';
		}

		if (map[h - 1][i] == '#')
		{
			map[h - 1][i] = '@';
		}
	}

	for (int i = 0; i < h; i++)
	{
		if (map[i][0] == '#')
		{
			map[i][0] = '@';
		}

		if (map[i][w-1] == '#')
		{
			map[i][w-1] = '@';
		}
	}
}

int main()
{
	int T = 0;
	
	scanf("%d", &T);

	while (T--)
	{
		init();

		scanf("%d %d", &h, &w);

		for (int i = 0; i < h; i++)
		{
			getchar();

			for (int j = 0; j < w; j++)
			{
				scanf("%1c", &map[i][j]);

				if (map[i][j] == '$')
				{
					if (person_num == 0)
					{
						p1y = i;
						p1x = j;
					}
					else if (person_num == 1)
					{
						p2y = i;
						p2x = j;
					}

					q.push(make_pair(make_pair(i, j), person_num++));
				}
			}
		}

		changeDoor();

		BFS();

		printf("%d\n", door);
	}

	return 0;
}