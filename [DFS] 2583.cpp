#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int visit[101][101] = { 0, };

int map[101][101] = { 0, };

int M = 0, N = 0, K = 0;

int dy[5] = { -1, 0, 1, 0};
int dx[5] = { 0, -1, 0, 1};

int cnt = 0;

vector<int> ans;

void DFS(int y, int x)
{
	visit[y][x] = 1;

	++cnt;

	for (int i = 0; i < 5; i++)
	{
		int Y = y + dy[i];
		int X = x + dx[i];

		if (Y < 0 || Y >= M || X < 0 || X >= N || visit[Y][X] == 1 || map[Y][X] == 1) continue;

		visit[Y][X] = 1;	

		DFS(Y, X);
	}
}

int main(void)
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	scanf("%d %d %d", &M, &N, &K);

	while (K--)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int i =y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				if (map[i][j] == 1) continue;

				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0 && map[i][j] == 0)
			{
				cnt = 0;

				DFS(i, j);

				ans.push_back(cnt);	
			}
		}
	}

	int ans_size = ans.size();

	printf("%d\n", ans_size);

	sort(ans.begin(), ans.end());

	for (auto i : ans)
	{
		printf("%d ", i);
	}

	printf("\n");

	return 0;
}