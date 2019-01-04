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

int main(void)
{
	int N = 0, i = 2;

	scanf("%d", &N);

	vector<int> v;

	while(N != 1)
	{
		while (N % i == 0)
		{
			v.push_back(i);

			N /= i;
		}

		++i;
	}

	sort(v.begin(), v.end());

	for (auto i : v) printf("%d\n", i);
	
	return 0;
}