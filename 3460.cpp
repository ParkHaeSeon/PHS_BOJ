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

vector<int> b(int n)
{
	vector<int> v;
	int idx = 0;

	while (n != 0)
	{
		if (n % 2 == 1)
		{
			v.push_back(idx);
		}

		n /= 2;
		++idx;
	}

	return v;
}

int main(void)
{
	int T = 0, n = 0;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		vector<int> v = b(n);

		//sort(v.begin(), v.end());

		for (auto i : v)
		{
			printf("%d ", i);
		}

		printf("\n");
	}

	return 0;
}