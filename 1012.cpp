#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int M = 0, N = 0; // M : 배추밭의 가로 길이, N : 배추밭의 세로 길이
int K = 0; // K : 배추가 심어져 있는 위치의 개수
int X = 0, Y = 0; // X, Y : 배추의 위치
int W = 0; // 배추 흰 지렁이 마리의 개수
int field[51][51] = { 0, }; // 밭

int dx[4] = { 0, -1, 1, 0};
int dy[4] = { -1, 0, 0, 1 };

int visit[51][51] = { 0, }; // 방문 여부

void DFS(int start, int end)
{
	int nx = 0, ny = 0;
	
	visit[start][end] = 1;

	for (int i = 0; i < 4; i++)
	{
		ny = start + dy[i];
		nx = end + dx[i];

		if (nx < 0 || ny < 0 || nx > M || ny > N) continue;

		if (field[ny][nx] == 1 && visit[ny][nx] == 0)
		{
			DFS(ny, nx);
		}
		
	}
}

int main()
{
	int T = 0; // 테스트 케이스의 개수

	scanf("%d", &T); // 테스트 케이스 입력


	while (T > 0)
	{
		scanf("%d %d %d", &M, &N, &K);

		while (K > 0)
		{
			scanf("%d %d", &X, &Y);

			field[Y][X] = 1;

			--K;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (field[i][j] == 1 && visit[i][j] == 0)
				{
					++W;

					DFS(i, j);
				}
			}
		}

		printf("%d\n", W);

		memset(visit, 0, sizeof(visit));
		memset(field, 0, sizeof(field));

		W = 0;

		--T;
	}

	return 0;
}