// 도움 많이 된 사이트 : http://jason9319.tistory.com/217

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N = 0; // 세로 = y = N
int M = 0; // 가로 = x = M

int visit[11][11][11][11];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int ry, rx, by, bx;

char map[11][11];

queue<pair<pair<int, int>, pair<int, int> > > q;

int BFS()
{
	q.push(make_pair(make_pair(ry, rx), make_pair(by, bx)));

	visit[ry][rx][by][bx] = 1;

	int Cnt = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		for (int i = 0; i < qSize; i++)
		{
			int Ry = q.front().first.first;
			int Rx = q.front().first.second;

			int By = q.front().second.first;
			int Bx = q.front().second.second;

			q.pop();

			if (map[Ry][Rx] == 'O' && map[Ry][Rx] != map[By][Bx])
			{
				return Cnt;
			}
			
			for (int j = 0; j < 4; j++)
			{
				int RedY = Ry;
				int RedX = Rx;
				int BlueY = By;
				int BlueX = Bx;

				//if (RedY + dy[j] <= 0 || RedY + dy[j] > N || RedX + dx[j] <= 0 || RedX + dx[j] > M) continue;

				//if (BlueY + dy[j] <= 0 || BlueY + dy[j] > N || BlueX + dx[j] <= 0 || BlueX + dx[j] > M) continue;

				while (map[RedY + dy[j]][RedX + dx[j]] != '#' && map[RedY][RedX] != 'O')
				{
					RedY += dy[j];
					RedX += dx[j];
				}

				while (map[BlueY + dy[j]][BlueX + dx[j]] != '#' && map[BlueY][BlueX] != 'O')
				{
					BlueY += dy[j];
					BlueX += dx[j];
				}

				if (RedY == BlueY && RedX == BlueX)
				{
					if (map[RedY][RedX] == 'O') continue;

					if (abs(RedY - Ry) + abs(RedX - Rx) < abs(BlueY - By) + abs(BlueX - Bx))
					{
						BlueY -= dy[j];
						BlueX -= dx[j];
					}
					else
					{
						RedY -= dy[j];
						RedX -= dx[j];
					}
				}

				if (visit[RedY][RedX][BlueY][BlueX] == 1) continue;
				
				q.push(make_pair(make_pair(RedY, RedX), make_pair(BlueY, BlueX)));

				visit[RedY][RedX][BlueY][BlueX] = 1;
			}
		}

		if (Cnt >= 10) return -1;

		++Cnt;
	}

	return -1;
}

int main(void)
{
	scanf("%d %d", &N, &M); // 세로 N, 가로 M

	for (int i = 1; i <= N; i++) // 세로 y
	{
		for (int j = 1; j <= M; j++) // 가로 x
		{
			scanf("%c", &map[i][j]);

			if (map[i][j] == 'R')
			{
				ry = i;
				rx = j;
			}
			else if (map[i][j] == 'B')
			{
				by = i;
				bx = j;
			}
		}
	}

	printf("%d\n", BFS());

	return 0;
}
