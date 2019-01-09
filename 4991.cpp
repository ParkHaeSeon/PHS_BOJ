
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

int w = 0, h = 0;

char room[22][22];

vector<pair<int, int> > dirty;

int dist[11][11] = { 0, }; // [행][열] = [행]에서 [열]로 가는 최단 거리

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool visit_bt[11] = { false, }; // backtracking() 함수 전용 visit 방문 처리 배열

int result = 0;

void backtracking(int now, int total, int pos)
{
	if (pos == dirty.size())
	{
		result = min(result, total);

		return;
	}

	for (int next = 1; next < dirty.size(); next++) // 0은 무조건 포함시켜야함.
	{
		if (now == next) continue;

		if (!visit_bt[next])
		{
			visit_bt[next] = true;

			total += dist[now][next];

			backtracking(next, total, pos + 1);

			total -= dist[now][next];

			visit_bt[next] = false;
		}
	}
}

int BFS(pair<int, int> s, pair<int, int> e)
{
	queue<pair<int, int> > q;

	bool visit[22][22] = { false, };

	q.push(s);

	visit[s.first][s.second] = true;

	int ret = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int r = q.front().first;
			int c = q.front().second;

			q.pop();

			if (r == e.first && c == e.second) return ret;

			for (int i = 0; i < 4; i++)
			{
				int y = r + dy[i];
				int x = c + dx[i];

				if (y < 0 || y >= h || x < 0 || x >= w || visit[y][x] || room[y][x] == 'x') continue;

				q.push({ y, x });
				visit[y][x] = true;
			}
		}

		++ret;
	}

	return -1;
}

void init()
{
	memset(visit_bt, false, sizeof(visit_bt));

	for (int i = 0; i < 11; i++) for (int j = 0; j < 11; j++) dist[i][j] = -1;

	result = 22 * 22;

	dirty.clear();
}

int main(void)
{
	while (1)
	{
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0) break;

		init();

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf(" %1c", &room[i][j]);

				if (room[i][j] == 'o') dirty.insert(dirty.begin(), { i, j });
				else if (room[i][j] == '*') dirty.push_back({ i, j });
			}
		}

		bool stop = false;

		for (int i = 0; i < dirty.size(); i++)
		{
			for (int j = 0; j < dirty.size(); j++)
			{
				if (i >= j) continue; // 시간 단축

				dist[i][j] = dist[j][i] = BFS(dirty.at(i), dirty.at(j));

				if (dist[i][j] == -1)
				{
					stop = true;
					break;
				}
			}

			if (stop) break;
		}

		if (stop)
		{
			printf("-1\n");
			continue;
		}

		backtracking(0, 0, 1);

		printf("%d\n", result);
	}

	return 0;
}