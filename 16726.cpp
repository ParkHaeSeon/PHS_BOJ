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

#define MAX 51

int R = 0, C = 0;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int number[MAX][MAX] = { 0, };

char Map[MAX][MAX];

vector<int> point, Left, Right;

vector<vector<int> > v;

vector<bool> visit;

bool DFS(int start)
{
	if (visit[start]) return false;

	visit[start] = true;

	for (auto next : v[start])
	{
		if (Right[next] == -1 || DFS(Right[next]))
		{
			Left[start] = next;
			Right[next] = start;

			return true;
		}
	}

	return false;
}

int bm()
{
	Left = vector<int>(R*C + 1, -1);
	Right = vector<int>(R*C + 1, -1);

	int ret = 0;

	for (int i = 0; i < point.size(); i++)
	{
		visit = vector<bool>(R*C + 1, false);;

		if (DFS(i)) ++ret;
	}

	return ret / 2;
	// 2개씩 짝이므로, 나누기 2를 해준다.
}

int main(void)
{
	int xcnt = 0;

	scanf("%d %d", &R, &C);

	v = vector<vector<int> >(R*C + 1);

	int cnt = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Map[i][j];

			if (Map[i][j] == 'X') ++xcnt;

			point.push_back(cnt);

			number[i][j] = cnt++;
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Map[i][j] == 'X') continue;

			for (int k = 0; k < 4; k++)
			{
				int y = i + dy[k];
				int x = j + dx[k];

				if (y < 0 || y >= R || x < 0 || x >= C || Map[y][x] == 'X') continue;

				v[number[i][j]].push_back(number[y][x]);
			}
		}
	}

	int two = bm();

	int one = R*C - 2 * two - xcnt;

	printf("%d\n", two + one);

	return 0;
}