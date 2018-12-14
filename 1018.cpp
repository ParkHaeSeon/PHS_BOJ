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

int Map1[51][51] = { 0, };
int Map2[51][51] = { 0, };

int v[51][51] = { 0, };

int N = 0, M = 0;
// 흰 색 = 1, 검은 색 = -1;

int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };

int w = 0, b = 0;

void init()
{
	Map1[0][0] = 1; // 하얀 색 먼저
	Map2[0][0] = -1; // 검은 색 먼저

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (i + dy[k] >= N || j + dx[k] >= M) continue;

				Map1[i + dy[k]][j + dx[k]] = Map1[i][j] * -1;
				Map2[i + dy[k]][j + dx[k]] = Map2[i][j] * -1;
			}
		}
	}
}

void calc(int r, int c)
{
	int wcnt = 0, bcnt = 0;

	for (int i = r; i < r + 8; i++)
	{
		for (int j = c; j < c + 8; j++)
		{
			if (Map1[i][j] != v[i][j]) ++wcnt;
			// 하얀 색을 먼저 칠한 판과 입력 받은 판에서 서로 다른 개수

			if (Map2[i][j] != v[i][j]) ++bcnt;
			// 검은 색을 먼저 칠한 판과 입력 받은 판에서 서로 다른 개수
		}
	}

	// 최솟값 갱신
	w = min(w, wcnt);
	b = min(b, bcnt);
}

int main(void)
{
	char a;

	w = b = INT32_MAX;

	scanf("%d %d", &N, &M);

	init();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a;

			if (a == 'W') v[i][j] = 1;		
			else if (a == 'B') v[i][j] = -1;		
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i + 8 > N || j + 8 > M) continue;

			calc(i, j);
		}
	}

	printf("%d\n", min(w, b));

	return 0;
}