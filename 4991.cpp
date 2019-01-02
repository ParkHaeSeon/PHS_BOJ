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

		// ������ ���̶��.
		if (dirty.at(i).second == 1)
		{
			dirty.at(i).second = 0;
			// �ٲ��ְ�

			BackTracking(pos + 1, next, sum + dist[now.first][now.second][next.first][next.second]);

			dirty.at(i).second = 1;
			// �ٽ� ������
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
		// INF�� �ʱ�ȭ ����� �Ѵ�.
		// �ֳ��ϸ�, ��Ʈ��ŷ���� ����� ���� sum�� INF�� �ʰ��ϴ��� �� �ϴ��� ���ο� ���� ������ �޶�����.

		scanf("%d %d", &c, &r);

		if (r == 0 && c == 0) break;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> Map[i][j];

				// �κ�
				if (Map[i][j] == 'o')
				{
					dirty.push_back({ { i, j }, 0 });

					ry = i;
					rx = j;
				}
				else if (Map[i][j] == '*') // ������ ĭ
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
					ó���� (cury != y || curx != x) ��� ���ǵ� �߰��߾��µ�,
					�����غ��� �̷����ϸ� �� �Ǿ���. ��� �������� �κ� 
					�� ��� �͵� ������ �Ÿ��� dist �迭�� �����߾�� �ߴ�.

					����, �ϳ��� �����ϰ� stop = true�� �ٲ�, break��(BFS�� return�̶�� ����)
					�߾��µ�, �̰͵� Ʋ����.
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