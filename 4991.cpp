#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

#define INF 21*21*21*21

char Map[21][21];

vector<pair<pair<int, int>, int> > dirty;

int ry = 0, rx = 0;

int r = 0, c = 0;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int dist[21][21][21][21] = { 0, };

int result = 0;

void BackTracking(int pos, pair<int, int> now, int sum)
{
	if (pos == dirty.size())
	{
		if (sum < result)
		{
			result = sum;
		}

		return;
	}

	for (int i = 0; i < dirty.size(); i++)
	{
		int y = dirty.at(i).first.first;
		int x = dirty.at(i).first.second;

		pair<int, int> next = dirty.at(i).first;

		// 더러운 곳이라면.
		if (dirty.at(i).second == 1)
		{
			dirty.at(i).second = 0;
			// 바꿔주고

			BackTracking(pos + 1, next, sum + dist[now.first][now.second][next.first][next.second]);

			dirty.at(i).second = 1;
			// 다시 원상태
		}
	}
}

int main(void)
{
	while (1)
	{
		result = INF;

		if (!dirty.empty()) dirty.clear();

		for (int a = 0; a < 21; a++)
			for (int b = 0; b < 21; b++)
				for (int cc = 0; cc < 21; cc++)
					for (int d = 0; d < 21; d++)
						dist[a][b][cc][d] = INF;
		// INF로 초기화 해줘야 한다.
		// 왜냐하면, 백트래킹으로 계산할 때에 sum이 INF를 초과하는지 안 하는지 여부에 따라 정답이 달라진다.

		scanf("%d %d", &c, &r);

		if (r == 0 && c == 0) break;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> Map[i][j];

				// 로봇
				if (Map[i][j] == 'o')
				{
					dirty.push_back({ { i, j }, 0 });

					ry = i;
					rx = j;
				}
				else if (Map[i][j] == '*') // 더러운 칸
				{
					dirty.push_back({ { i, j }, 1 });
				}
			}
		}

		for (int i = 0; i < dirty.size(); i++)
		{
			int cury = dirty.at(i).first.first;
			int curx = dirty.at(i).first.second;

			queue<pair<int, int> > q;

			bool visit[21][21] = { false, };

			bool stop = false;

			int ret = 0;

			q.push({ cury, curx });

			visit[cury][curx] = true;

			while (!q.empty())
			{
				int qSize = q.size();

				while (qSize--)
				{
					int y = q.front().first;
					int x = q.front().second;

					q.pop();

					/*
					처음에 (cury != y || curx != x) 라는 조건도 추가했었는데,
					생각해보니 이렇게하면 안 되었다. 모든 쓰레기들과 로봇 
					이 모든 것들 사이의 거리를 dist 배열에 저장했어야 했다.

					또한, 하나만 갱신하고 stop = true로 바꿔, break를(BFS의 return이라고 생각)
					했었는데, 이것도 틀리다.
					*/

					if ((Map[y][x] == '*' || Map[y][x] == 'o')) dist[cury][curx][y][x] = ret;			

					for (int j = 0; j < 4; j++)
					{
						int ny = y + dy[j];
						int nx = x + dx[j];

						if (ny < 0 || ny >= r || nx < 0 || nx >= c || Map[ny][nx] == 'x' || visit[ny][nx]) continue;

						q.push({ ny, nx });
						visit[ny][nx] = true;
					}
				}

				if (stop) break;

				++ret;
			}		
		}
		
		BackTracking(1, { ry, rx }, 0);

		if (result == INF) printf("-1\n");	
		else printf("%d\n", result);
	}

	return 0;
}