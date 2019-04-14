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
#include <set>
#include <sstream>
#include <tuple>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define value 100

int Map[55][55] = { 0, }, arr[55][55] = { 0, }, N = 0, M = 0, MIN_time = 0;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

vector<pair<int, int> > v;

bool zero()
{
	for (int i = 0; i < N; i++)	
		for (int j = 0; j < N; j++)
			if (Map[i][j] == 0) return true;

	return false;
}

int spread(vector<pair<int, int> > vc)
{
	int time = 0;

	bool visit[55][55] = { false, };

	queue<pair<int, int> > q;

	for (int i = 0; i < vc.size(); i++)
	{
		Map[vc.at(i).first][vc.at(i).second] = value;
		visit[vc.at(i).first][vc.at(i).second] = true;
		q.push({ vc.at(i).first, vc.at(i).second });
	}

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int r = q.front().first;
			int c = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int y = r + dy[i];
				int x = c + dx[i];

				if (y < 0 || y >= N || x < 0 || x >= N || visit[y][x] || Map[y][x] == 1) continue;

				Map[y][x] = value;
				q.push({ y, x });
				visit[y][x] = true;
			}
		}

		++time;
	}
	
	return time - 1;
}

void update()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)	
			Map[i][j] = arr[i][j];
}

void simulation(vector<pair<int, int> > vc, int pos)
{
	if (vc.size() == M)
	{
		update();

		int mt = spread(vc);

		if (zero()) return;		

		MIN_time = min(MIN_time, mt);

		return;
	}

	for (int i = pos; i < v.size(); i++)
	{
		vc.push_back(v.at(i));

		simulation(vc, i + 1);

		vc.pop_back();
	}
}

int main(void)
{
	MIN_time = 1e9;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &Map[i][j]);

			arr[i][j] = Map[i][j];

			if (Map[i][j] == 2) v.push_back({ i,j });		
		}

	vector<pair<int, int> > vc;

	simulation(vc, 0);

	if (MIN_time == 1e9) MIN_time = -1;

	printf("%d\n", MIN_time);
	
	return 0;
}
