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

bool cmp(int &a, int &b)
{
	return a > b;
}

int main(void)
{
	int T = 0, N = 0, M = 0, document = 0;

	scanf("%d", &T);

	while (T--)
	{
		queue<pair<int, int> > q;
		vector<int> v;
		bool stop = false;
		int p = 0;
		
		scanf("%d %d", &N, &M);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &document);

			q.push({ i, document });

			v.push_back(document);
		}

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < v.size(); i++)
		{
			while (1)
			{
				if (v.at(i) == q.front().second)
				{
					++p;

					if (M == q.front().first)
					{
						stop = true;
					}

					if (!q.empty()) q.pop();

					break;
				}
				else
				{
					q.push(q.front());
					q.pop();
				}
			}

			if (stop)
			{
				break;
			}
		}

		printf("%d\n", p);
	}
	
	return 0;
}