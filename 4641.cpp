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

vector<int> v;

int search()
{
	bool visit[101] = { false, };

	memset(visit, false, sizeof(visit));

	int ret = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int n = v.at(i);

		for (int j = i + 1; j < v.size(); j++)
		{
			if (2 * v.at(i) == v.at(j) || 2*v.at(j) == v.at(i))
			{
				++ret;
			}
		}
	}

	return ret;
}

int main(void)
{
	int n = 0;

	while (1)
	{
		scanf("%d", &n);

		if (n == -1) break;
		else if (n != -1 && n != 0) v.push_back(n);
		else if (n == 0)
		{
			printf("%d\n", search());
			v.clear();
		}
	}

	return 0;
}