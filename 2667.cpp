#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int map[26][26] = { 0, };

int visit[26][26] = { 0, };

int N = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

vector<int> v;

int Cnt = 1;

int DFS(int y, int x, int gn)
{
	visit[y][x] = 1;
	map[y][x] = gn;

	for (int i = 0; i < 4; i++)
	{
		int Y = y + dy[i];
		int X = x + dx[i];

		if (Y <= 0 || Y > N || X <= 0 || X > N || map[Y][X] == 0 || visit[Y][X] == 1) continue;

		++Cnt;

		DFS(Y, X, gn);
	}

	return Cnt;
}

int main(void)
{
	int groupNumber = 1;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] !=0 && visit[i][j] == 0)
			{
				v.push_back(DFS(i, j, groupNumber++)); // i:세로, j:가로
				Cnt = 1;
			}
		}
	}

	printf("%d\n", groupNumber-1);

	sort(v.begin(), v.end());

	for (int next : v)
	{
		printf("%d\n", next);
	}
	
	return 0;
}