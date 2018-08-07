#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N = 0, M = 0;

int answer = 987654321;

bool used[10] = { false, };

int map[52][52] = { 0, };

vector<pair<int, int> > house;
vector<pair<int, int> > chicken;

int DFS(vector<pair<int, int> > vc, int cnt)
{
	if (vc.size() == M)
	{
		int sum = 0;

		for (int i = 0; i < house.size(); i++)
		{
			int hy = house[i].first;
			int hx = house[i].second;

			int min_distance_hc = 987654321;

			for (int j = 0; j < M; j++)
			{
				int cy = vc[j].first;
				int cx = vc[j].second;

				min_distance_hc = min(min_distance_hc, abs(hy - cy) + abs(hx - cx));
			}

			sum += min_distance_hc;
		}

		return sum;
	}

	for (int i = cnt; i < chicken.size(); i++)
	{
		vc.push_back(chicken[i]);
		answer = min(answer, DFS(vc, i + 1));
		vc.pop_back();
	}

	return answer;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1)
			{
				house.push_back({ i,j });
			}
			else if (map[i][j] == 2)
			{
				chicken.push_back({ i,j });
			}
		}
	}

	vector<pair<int, int> > vc;

	DFS(vc, 0);

	printf("%d\n", answer);

	return 0;
}