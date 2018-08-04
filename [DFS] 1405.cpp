#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int N = 0;

int visit[30][30] = { 0, };

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

double vec[4];
double result = 0;

void DFS(int r, int c, double ans)
{
	if (N == 0)
	{
		result += ans;

		return;
	}

	visit[r][c] = 1;

	for (int i = 0; i < 4; i++)
	{
		int y = r + dy[i];
		int x = c + dx[i];

		if (visit[y][x] == 1) continue;
		
		N -= 1;

		DFS(y, x, ans * vec[i]);

		N += 1;

		visit[y][x] = -1;
	}
}

int main(void)
{
	int x = 0;

	memset(visit, -1, sizeof(visit));

	cin >> N;

	for (int i = 0; i < 4; i++)
	{
		cin >> vec[i];

		vec[i] *= 0.01;
	}

	DFS(15, 15, 1.0);

	printf("%.10f\n", result);

	return 0;
}