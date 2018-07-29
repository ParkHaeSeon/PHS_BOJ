#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int bridge = 987654321; // 최소 길이의 다리
int N = 0; // 섬의 가로, 세로 크기

int visit[101][101] = { 0, };
int nation[101][101] = { 0, };

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void DFS(int y, int x, int G_number) // 섬 그룹 번호 부여
{
	visit[y][x] = 1; // 방문 표시
	nation[y][x] = G_number; // 그룹 번호 부여

	for (int i = 0; i < 4; i++)
	{
		int Y = y + dy[i];
		int X = x + dx[i];

		if (Y <= 0 || X <= 0 || Y > N || X > N || nation[Y][X] == 0 || visit[Y][X] == 1) continue;

		DFS(Y, X, G_number);
	}
}

int BFS(int gn) // 섬 확장
{
	queue<pair<int, int> > q;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (nation[i][j] == gn)
			{
				visit[i][j] = 1;
				q.push(make_pair(i, j)); // (세로, 가로)
			}
		}
	}

	int length = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		for (int i = 0; i < qSize; i++)
		{
			int y = q.front().first;
			int x = q.front().second;

			q.pop();

			for (int a = 0; a < 4; a++)
			{
				int Y = y + dy[a];
				int X = x + dx[a];

				if (Y <= 0 || X <= 0 || Y > N || X > N) continue;

				if (nation[Y][X] != 0 && nation[Y][X] != gn)
				{
					return length;
				}

				if (nation[Y][X] == 0 && visit[Y][X] == 0) // 바다도 q에 push
				{
					visit[Y][X] = 1;

					q.push(make_pair(Y, X));
				}
			}		
		}

		++length;
	}
}

int main(void)
{
	int groupNumber = 1;

	scanf("%d", &N); // N*N

	for (int i = 1; i <= N; i++) // 세로
	{
		for (int j = 1; j <= N; j++) // 가로
		{
			scanf("%d", &nation[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (nation[i][j] != 0 && visit[i][j] == 0)
			{
				DFS(i, j, groupNumber++); // 세로(y), 가로(x), 섬 그룹 번호 순서로 DFS 함수에 전달
			}
		}
	}

	for (int i = 1; i < groupNumber; i++)
	{
		memset(visit, 0, sizeof(visit));
		bridge = min(bridge, BFS(i));
	}

	printf("%d\n", bridge);

	return 0;
}
