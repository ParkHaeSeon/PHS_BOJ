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

typedef struct gsb
{
	int gold;
	int silver;
	int bronze;
}gsb;

vector<gsb> v[1001];

gsb input;

int main(void)
{
	int N = 0, K = 0;

	int n = 0, g = 0, s = 0, b = 0;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &n, &g, &s, &b);

		input.gold = g;
		input.silver = s;
		input.bronze = b;

		v[n].push_back(input);
	}

	int wg = v[K].at(0).gold;
	int ws = v[K].at(0).silver;
	int wb = v[K].at(0).bronze;

	int result = 1;

	for (int i = 1; i <= N; i++)
	{
		if (i == K) continue;

		if (v[i].at(0).gold > wg)
		{
			++result;
			continue;
		}

		if (v[i].at(0).gold == wg && v[i].at(0).silver > ws)
		{
			++result;
			continue;
		}

		if (v[i].at(0).gold == wg && v[i].at(0).silver == ws && v[i].at(0).bronze > wb)
		{
			++result;
			continue;
		}
	}

	printf("%d\n", result);

	return 0;
}