// BOJ 1520 내리막 길

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

int map[501][501] = { 0, }; // map[세로][가로]
int dp[501][501] = { 0, }; // dp[세로][가로] : (1, 1)에서 (세로, 가로) 지점으로 갈 수 있는 경우의 수
int dx[4] = { -1, 0, 1, 0 }; // 상하좌우
int dy[4] = { 0, -1, 0, 1 }; // 상하좌우

int M = 0; // 지도의 세로의 크기 = y = M
int N = 0; // 지도의 가로의 크기 = x = N

int downhill(int y, int x)
{
	if (dp[y][x] != -1) return dp[y][x];
	if (y == M && x == N) return 1;

	dp[y][x] = 0;

	for (int h = 0; h <= 3; h++)
	{
		int dy_i = y + dy[h];

		int dx_j = x + dx[h];

		if (dy_i <= 0 || dy_i > M || dx_j <= 0 || dx_j > N || map[dy_i][dx_j] == 0) continue;

		if (map[y][x] > map[dy_i][dx_j])
		{
			dp[y][x] += downhill(dy_i, dx_j);
		}
	}

	return dp[y][x];
}

int main(void)
{
	scanf("%d %d", &M, &N); // 세로 크기 입력, 가로 크기 입력

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));

	printf("%d\n", downhill(1, 1));

	return 0;
}
