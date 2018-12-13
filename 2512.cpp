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

int sum = 0;

int bs(int left, int right)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int s = 0;

		for (int i = 0; i < v.size(); i++)
		{
			int add = v.at(i);

			if (middle <= add) add = middle;

			s += add;
		}

		if (s == sum) return middle;
		else if (s > sum) --right;
		else ++left;
	}

	return right;
}

int main(void)
{
	int N = 0, money = 0, MAX = INT32_MIN;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &money);

		MAX = max(money, MAX);

		v.push_back(money);
	}

	scanf("%d", &sum);

	printf("%d\n", bs(1, MAX));

	return 0;
}