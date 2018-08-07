#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N = 0, M = 0;

queue<int> q;

queue<int> ans;

int main(void)
{
	int x = 0;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	printf("<");

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M-1; j++)
		{
			q.push(q.front());
			q.pop();
		}

		ans.push(q.front());
		q.pop();
	}

	while (!ans.empty())
	{
		printf("%d", ans.front());
		ans.pop();
		if(!ans.empty()) printf(", ");
	}
	
	printf(">\n");

	return 0;
}
