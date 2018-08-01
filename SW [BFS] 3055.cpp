#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int R = 0; // R 세로 y
int C = 0; // C 가로 x

int Sy = 0, Sx = 0; // 고슴도치
int Dy = 0, Dx = 0; // 비버의 굴(최종 목적지)

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

char map[51][51];

int visit[51][51][3]; // 0 : 물 미리 한 칸, 1 : 고, 2 : 물 

queue<pair<pair<int, int>, int > > q;

int BFS()
{
	int ret = 0;

	q.push(make_pair(make_pair(Sy, Sx), 1)); // 고슴도치 : 1

	while (!q.empty())
	{
		int qSize = q.size();
		
		while (qSize--)
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int sit = q.front().second;

			q.pop();

			if (map[y][x] == 'D' && sit == 1)
			{
				return ret;
			}

			for (int i = 0; i < 4; i++)
			{
				int Y = y + dy[i];
				int X = x + dx[i];

				if (Y < 0 || Y >= R || X < 0 || X >= C) continue;

				if (sit == 1 && visit[Y][X][1] == -1) // 고슴도치
				{
					if (map[Y][X] == '*' || map[Y][X] == 'X') continue;

					q.push(make_pair(make_pair(Y, X), 1));

					visit[Y][X][1] = 1;
				}
				else if (sit == 2 && visit[Y][X][2] == -1) // 물
				{
					if (map[Y][X] == 'D' || map[Y][X] == 'X') continue;

					q.push(make_pair(make_pair(Y, X), 2));

					map[Y][X] = '*';

					visit[Y][X][2] = 1;
				}
			}
		}

		++ret;
	}

	return -1;
}

int main(void)
{
	memset(visit, -1, sizeof(visit));

	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		getchar();

		for (int j = 0; j < C; j++)
		{
			scanf("%1c", &map[i][j]);
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'S')
			{
				Sy = i;
				Sx = j;
			}
			else if (map[i][j] == '*' && visit[i][j][0] == -1)
			{
				for (int k = 0; k < 4; k++)
				{
					int wy = i + dy[k];
					int wx = j + dx[k];

					if (wy < 0 || wy >= R || wx < 0 || wx >= C || map[wy][wx] == 'D' || map[wy][wx] == 'X' || map[wy][wx] == '*' || map[wy][wx] == 'S') continue;

					map[wy][wx] = '*';

					visit[wy][wx][0] = 1;

					q.push(make_pair(make_pair(i, j), 2)); // 물 : 2
				}
			}
		}
	}

	int ans = BFS();

	if (ans != -1) printf("%d\n", ans);
	else printf("KAKTUS\n");

	return 0;
}