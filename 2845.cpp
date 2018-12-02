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

int main(void)
{
	int L = 0, P = 0, n = 0;

	scanf("%d %d", &L, &P);

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);

		v.push_back(n - (L*P));
	}

	for (auto i : v)
	{
		printf("%d ", i);
	}

	return 0;
}