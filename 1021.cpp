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

vector<int> v, q;

int result = 0;

int main(void)
{
	int N = 0, M = 0, input = 0;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		q.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &input);

		v.push_back(input);
	}

	for (int i = 0; i < v.size(); i++)
	{
		int idx = 1;
		int qSize = q.size();

		for (int j = 0; j < q.size(); j++)
		{
			if (v.at(i) == q.at(j)) break;

			++idx;
		}

		int head = abs(1 - idx);
		int tail = abs(qSize - idx);

		if (head <= tail)
		{
			while (head--)
			{
				q.push_back(q.at(0));
				q.erase(q.begin());

				++result;
			}
		}
		else
		{
			++tail;
			while (tail--)
			{
				q.insert(q.begin(), q.at(q.size() - 1));

				q.erase(q.end() - 1);

				++result;
			}
		}

		q.erase(q.begin());
	}

	printf("%d\n", result);

	return 0;
}