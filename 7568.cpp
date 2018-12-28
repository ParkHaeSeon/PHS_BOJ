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

typedef struct wh
{
	int weight;
	int height;
}wh;

vector<wh> v;
vector<int> Rank;

wh p;

int main(void)
{
	int N = 0, w = 0, h = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &w, &h);

		p.weight = w;
		p.height = h;

		v.push_back(p);
	}

	for (int i = 0; i < v.size(); i++)
	{
		int r = 1;

		for (int j = 0; j < v.size(); j++)
		{
			if (v.at(j).weight > v.at(i).weight && v.at(j).height > v.at(i).height)
			{
				++r;
			}
		}

		Rank.push_back(r);
	}

	for (auto r : Rank) printf("%d ", r);
	printf("\n");
	
	return 0;
}