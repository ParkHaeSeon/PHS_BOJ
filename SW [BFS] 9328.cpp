#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int T = 0;

int h = 0, w = 0;

int dy[5] = { -1, 0, 1, 0, 0 };
int dx[5] = { 0, -1, 0, 1, 0 };

char map[102][102];

bool update = true;

bool keys[200] = { false, };

bool visit[102][102] = { false, };

string alreadyKeys;

int ans = 0;

void BFS(int R, int C)
{
	queue<pair<int, int> > q;

	q.push({ R, C });

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int r = q.front().first;
			int c = q.front().second;

			q.pop();

			for (int i = 0; i < 5; i++)
			{
				int y = r + dy[i];
				int x = c + dx[i];

				if (y < 0 || y >= h || x < 0 || x >= w || map[y][x] == '*' || visit[y][x]) continue;		

				if ('A' <= map[y][x] && map[y][x] <= 'Z')
				{
					int tointKey = map[y][x] + 32;

					if (keys[tointKey])
					{
						map[y][x] = '.';
						q.push({ y, x });
					}
				}
				else if ('a' <= map[y][x] && map[y][x] <= 'z')
				{
					visit[y][x] = true;

					int tointKey = map[y][x];

					keys[tointKey] = true;
					map[y][x] = '.';
					update = true;
					q.push({ y, x });
					
				}
				else if (map[y][x] == '$')
				{
					visit[y][x] = true;
					++ans;
					map[y][x] = '.';
					q.push({ y, x });
					
				}
				else if (map[y][x] == '.')
				{
					visit[y][x] = true;
					q.push({ y, x });
					
				}
			}
		}
	}
}

void init()
{
	ans = 0;

	memset(keys, false, sizeof(keys));
}

int main(void)
{
	scanf("%d", &T);

	while (T--)
	{
		init();

		scanf("%d %d", &h, &w);

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		cin >> alreadyKeys;

		if (alreadyKeys[0] != '0')
		{
			int len = alreadyKeys.length();

			for (int i = 0; i < len; i++)
			{
				int tointKey = alreadyKeys[i];

				keys[tointKey] = true;
			}
		}
		else alreadyKeys[0] = true; // no alreadykeys
		
		update = true;

		while (update)
		{
			update = false;

			memset(visit, false, sizeof(visit));

			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					if (i == 0 || j == 0 || i == h - 1 || j == w - 1)
					{
						if (map[i][j] == '*' || visit[i][j]) continue;

						if ('A' <= map[i][j] && map[i][j] <= 'Z')
						{
							int tointKey = map[i][j] + 32;

							if (keys[tointKey])
							{
								BFS(i, j);
							}
						}
						else if (map[i][j] == '.')
						{
							BFS(i, j);
						}
						else if (map[i][j] == '$')
						{
							BFS(i, j);
						}
					}
				}
			}
		}
		
		printf("%d\n", ans);
	}

	return 0;
}
