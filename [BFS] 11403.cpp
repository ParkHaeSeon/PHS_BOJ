#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N = 0;

int arr[101][101] = { 0, };
int result[101][101] = { 0, };

bool visit[101] = { false, };

void BFS()
{
	for (int i = 0; i < N; i++)
	{
		queue<int> q;

		memset(visit, false, sizeof(visit));

		q.push(i);

		while (!q.empty())
		{
			int qSize = q.size();

			while (qSize--)
			{
				int here = q.front();

				q.pop();

				for (int j = 0; j < N; j++)
				{
					if (arr[here][j] == 1 && !visit[j])
					{
						visit[j] = true;

						result[here][j] = 1;

						q.push(j);
					}
				}
			}
		}

		for (int j = 0; j < N; j++)
		{
			if (visit[j]) printf("1 ");
			else printf("0 ");
		}

		printf("\n");

	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	BFS();

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", result[i][j]);
		}

		printf("\n");
	}*/

	return 0;
}