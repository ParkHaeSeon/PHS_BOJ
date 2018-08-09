#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N = 0;

int person[21][21] = { 0, };

int result = 987654321;

void DFS(int pos, vector<int> vc)
{
	if (vc.size() == N / 2)
	{
		vector<int> other_team;
		bool visit[21] = { false, };
		int value[2] = { 0, };

		for (int i = 0; i < vc.size(); i++)
		{
			visit[vc[i]] = true;
		}

		for (int i = 0; i < N; i++)
		{
			if (!visit[i])
			{
				other_team.push_back(i);
			}
		}

		/*for (int i = 0; i < vc.size(); i++)
		{
			other_team.push_back((N - 1) - vc[i]);
		}*/

		for (int i = 0; i < vc.size()-1; i++)
		{
			for (int j = i+1; j < vc.size(); j++)
			{
				value[0] += (person[vc[i]][vc[j]] + person[vc[j]][vc[i]]);
			}
		}

		for (int i = 0; i < other_team.size() - 1; i++)
		{
			for (int j = i + 1; j < other_team.size(); j++)
			{
				value[1] += (person[other_team[i]][other_team[j]] + person[other_team[j]][other_team[i]]);
			}
		}

		result = min(result, abs(value[0] - value[1]));

		/*printf("\n==========================\n");
		printf("value[0] : %d, value[1] : %d\n", value[0], value[1]);
		printf("result : %d\n", result);*/

		return;
	}

	for (int i = pos; i < N; i++)
	{
		vc.push_back(i);
		DFS(i + 1, vc);
		vc.pop_back();
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &person[i][j]);
		}
	}

	vector<int> v;

	DFS(0, v);

	printf("%d\n", result);

	return 0;
}

/*
#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N = 0;

int num[22][22] = { 0, };

int team[22] = { 0, };

int result = 987654321;

void DFS(int cnt)
{
	if (cnt == N)
	{
		int value[2] = { 0, };

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (team[i] == 1 && team[j] == 1)
				{
					value[0] += num[i][j];
				}
				else if (team[i] == 2 && team[j] == 2)
				{
					value[1] += num[i][j];
				}
			}
		}

		result = min(result, abs(value[0] - value[1]));

		return;
	}

	team[cnt] = 1;
	DFS(cnt + 1);

	team[cnt] = 2;
	DFS(cnt + 1);
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &num[i][j]);
		}
	}

	DFS(0);

	printf("%d\n", result);

	return 0;
}
*/