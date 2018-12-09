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

void change(int left, int right)
{
	while (1)
	{
		swap(v.at(left), v.at(right));

		++left;
		--right;

		if (left >= right) break;
	}
}

int main(void)
{
	for (int i = 1; i <= 20; i++)
	{
		v.push_back(i);
	}

	int left = 0, right = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d", &left, &right);

		--left;
		--right;

		change(left, right);
	}

	for (auto i : v) printf("%d ", i);
	printf("\n");

	return 0;
}