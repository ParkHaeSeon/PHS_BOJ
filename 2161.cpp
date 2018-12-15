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
	int N = 0;

	queue<int> q;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		q.push(i);

	while (!q.empty())
	{
		printf("%d ", q.front());

		q.pop();

		if (q.empty()) break;

		q.push(q.front());

		q.pop();	
	}

	printf("\n");

	return 0;
}