// 1012번 : 유기농 배추
// 깊이 우선 탐색(DFS)

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int T = 0; // 테스트 케이스의 개수
int M = 0; // 배추밭의 가로 길이
int N = 0; // 배추밭의 세로 길이
int K = 0; // 배추가 심어져 있는 위치의 개수
 
int Field[51][51] = { 0, }; // 배추 밭
int visit[51][51] = { 0, }; // 방문 여부

int white = 0; // 배추 흰 지렁이

int dx[4] = { -1, 0, 1, 0 }; // 4 방향
int dy[4] = { 0, -1, 0, 1 }; // 4 방향

void DFS(int x, int y)
{
	int nx = 0, ny = 0;

	visit[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{	
		nx = x + dx[i]; // 가로 방향(좌, 우)으로 움직임.
		ny = y + dy[i]; // 세로 방향(상, 하)으로 움직임.

		if (nx < 0 || ny < 0 || nx > M || ny > N) continue;

		if (Field[ny][nx] == 1 && visit[ny][nx] == 0)
		{
			DFS(nx, ny);
		}
	}
}

int main(void)
{
	int X = 0, Y = 0; // 배추의 위치 X(가로), Y(세로)

	scanf("%d", &T);

	while (T > 0)
	{
		scanf("%d %d %d", &M, &N, &K); // 가로, 세로, 배추 개수 입력

		for (int i = 0; i < K; i++)
		{
			scanf("%d %d", &X, &Y);

			Field[Y][X] = 1;
		}

		for (int j = 0; j < N ; j++) // 세로
		{
			for (int i = 0; i < M; i++) // 가로
			{
				if (Field[j][i] == 1 && visit[j][i] == 0) // 배추가 있는 위치이지만 방문을 하지 않았더라면
				{
					++white; // 무조건 배추 흰 지렁이의 수는 1 증가.

					DFS(i, j); // 가로 위치, 세로 위치를 넘겨준다. → 방문해준다.
				}
			}
		}

		printf("%d\n", white);

		white = 0; // 배추 흰 지렁이 초기화
		memset(Field, 0, sizeof(Field)); // 배추 밭 배열 0으로 초기화
		memset(visit, 0, sizeof(visit)); // 방문 여부 0으로 초기화

		--T;
	}

	return 0;
}

/*
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
*/
