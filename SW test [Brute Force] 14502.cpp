#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N = 0, M = 0;

int map[9][9] = { 0, };

int result = 0;

bool visit[9][9] = { false, };

void wall(int Cnt, int by, int bx)
{
	if (Cnt == 3)
	{
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 2 && !visit[i][j])
				{
					queue<pair<int, int> > q;

					visit[i][j] = true;

					q.push({ i, j });

					while (!q.empty())
					{
						int qSize = q.size();

						while (qSize--)
						{
							int y = q.front().first;
							int x = q.front().second;

							q.pop();

							for (int d = 0; d < 4; d++)
							{
								int ny = y + dy[d];
								int nx = x + dx[d];

								if ((0 <= ny && ny < N) && (0 <= nx && nx < M) && !visit[ny][nx] && map[ny][nx] == 0)
								{
									visit[ny][nx] = true;

									q.push({ ny, nx });
								}
							}	
						}
					}
				}
			}
		}

		int zero = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0 && !visit[i][j])
				{
					++zero;
				}
			}
		}

		result = max(zero, result);

		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ( (i == by && j > bx) || i > by )
			{
				if (map[i][j] == 0)
				{
					map[i][j] = 1;
					wall(Cnt + 1, i, j);
					map[i][j] = 0;
				}
			}
		}
	}
}

int main(void)
{
	int index = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	wall(0, -1, -1);

	printf("%d\n", result);

	return 0;
}

/*
#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N = 0, M = 0;

pair<int, int> map[100];

vector<pair<int, int> > virus;

int BFS(int temp[][9])
{
int Safe = 0;

queue<pair<int, int> > q;

int visit[9][9] = { 0, };

int arr[9][9] = { 0, };

for (int i = 0; i < N; i++)
{
for (int j = 0; j < M; j++)
{
arr[i][j] = temp[i][j];
}
}

for (int i = 0; i < virus.size(); i++)
{
q.push(virus[i]);
}

while (!q.empty())
{
int qSize = q.size();

while (qSize--)
{
int y = q.front().first;
int x = q.front().second;

q.pop();

if (visit[y][x] == 1) continue;

visit[y][x] = 1;

arr[y][x] = 2;

for (int i = 0; i < 4; i++)
{
int ny = y + dy[i];
int nx = x + dx[i];

if ((0 <= ny && ny < N) && (0 <= nx && nx < M) && arr[ny][nx] == 0)
{
q.push({ ny, nx });
}
}
}
}

for (int i = 0; i < N; i++)
{
for (int j = 0; j < M; j++)
{
if (arr[i][j] == 0)
{
++Safe;
}
}
}

return Safe;
}

int main(void)
{
int arr[9][9] = { 0, };

int index = 0, result = 0;

scanf("%d %d", &N, &M);

for (int i = 0; i < N; i++)
{
for (int j = 0; j < M; j++)
{
scanf("%d", &arr[i][j]);

map[index++] = { i,j };

if (arr[i][j] == 2)
{
virus.push_back({ i,j });
}
}
}

for (int point_1 = 0; point_1 < index - 2; point_1++)
{
for (int point_2 = point_1 + 1; point_2 < index - 1; point_2++)
{
for (int point_3 = point_2 + 1; point_3 < index; point_3++)
{

int y1 = map[point_1].first; int x1 = map[point_1].second;
int y2 = map[point_2].first; int x2 = map[point_2].second;
int y3 = map[point_3].first; int x3 = map[point_3].second;

if (arr[y1][x1] == 0 && arr[y2][x2] == 0 && arr[y3][x3] == 0)
{
arr[y1][x1] = arr[y2][x2] = arr[y3][x3] = 1;

int ret = BFS(arr);

result = max(result, ret);

arr[y1][x1] = arr[y2][x2] = arr[y3][x3] = 0;
}
}
}
}

printf("%d\n", result);

return 0;
}
*/