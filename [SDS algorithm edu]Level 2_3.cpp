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

typedef struct
{
	int x;
	int y;
	int order;
	bool live;
}restaurant;

vector<restaurant> v;

restaurant r;

bool cmp(const restaurant& a, const restaurant& b)
{
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int main(void)
{
	int N = 0, x = 0, y = 0, T = 0;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
		{
			scanf("%d %d", &x, &y);

			r.x = x;
			r.y = y;
			r.order = i;
			r.live = true;

			v.push_back(r);
		}

		sort(v.begin(), v.end(), cmp);

		printf("#%d", tc);

		int x = INT32_MAX;
		int y = INT32_MAX;

		for (int i = 0; i < v.size(); i++)
		{
			if(x <= v.at(i).x && y < v.at(i).y)
			{
				continue;
			}
			else if (x <= v.at(i).x && y == v.at(i).y)
			{
				continue;
			}
			else
			{
				x = v.at(i).x;
				y = v.at(i).y;

				printf(" %d", v.at(i).order);
			}
		}

		printf("\n");

		v.clear();
	}

	return 0;
}