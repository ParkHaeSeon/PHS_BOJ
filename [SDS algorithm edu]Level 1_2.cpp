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

int N = 0, M = 0;

int prisonerCar[51] = { 0, };
int forSave[51] = { 0, };

int totalPrisonerCar = 0;

vector<int> out;
vector<int> prisoner;

bool stop = false;

int result = 0;

void Chk(int start)
{
	if (start + totalPrisonerCar > out.size()) return;

	int ret = 0;

	for (int i = start; i < start + totalPrisonerCar; i++)
		--prisonerCar[out.at(i)];

	for (auto i : prisoner) 
		if (prisonerCar[i] != 0) ret = -1;

	if (ret == 0)
	{
		result = start + 1;
		stop = true;
	}
	else
	{
		for (int i = 1; i <= M; i++)
			prisonerCar[i] = forSave[i];
	}

	return;
}

int main(void)
{
	int color = 0, oc = 0, T = 0;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &color);

			prisonerCar[i] = color;
			forSave[i] = color;

			totalPrisonerCar += color;

			if (color != 0) prisoner.push_back(i);
		}

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &oc);

			out.push_back(oc);
		}

		for (int i = 0; i < out.size(); i++)
		{
			Chk(i);

			if (stop) break;
		}

		printf("#%d %d\n", tc, result);

		memset(prisonerCar, 0, sizeof(prisonerCar));
		memset(forSave, 0, sizeof(forSave));
		if (!out.empty()) out.clear();
		if (!prisoner.empty()) prisoner.clear();
		stop = false;
		result = 0;
		totalPrisonerCar = 0;
	}

	return 0;
}