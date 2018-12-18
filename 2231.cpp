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

int MIN = INT32_MAX;

void DivideSum(int N)
{
	for (int i = 1; i <= 1000000; i++)
	{
		string str = to_string(i);

		int sum = i;

		for (int j = 0; j < str.length(); j++)
			sum += str[j] - '0';

		if (sum == N) MIN = min(MIN, i);
	}
}

int main(void)
{
	int N = 0;

	scanf("%d", &N);

	DivideSum(N);

	if(MIN != INT32_MAX) printf("%d\n", MIN);
	else printf("0\n");

	return 0;
}