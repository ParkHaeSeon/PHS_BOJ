#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef struct WATER
{
	int a, b, c;
}WATER;

bool visit[201][201] = { false, };

bool water[201] = { false, };

int A = 0, B = 0, C = 0;

void BFS()
{
	queue<WATER> q;

	q.push({ 0, 0, C });

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int wa = q.front().a;
			int wb = q.front().b;
			int wc = q.front().c;

			q.pop();

			if (visit[wa][wb]) continue;

			visit[wa][wb] = true;

			if (wa == 0)
			{
				water[wc] = true;
			}

			// A ¡æ B
			if (wa + wb > B)
			{
				q.push({ wa + wb - B , B, wc });
			}
			else
			{
				q.push({ 0, wa + wb, wc });
			}

			// A ¡æ C
			if (wa + wc > C)
			{
				q.push({wa + wc - C, wb, C});
			}
			else
			{
				q.push({0, wb, wa + wc});
			}
			
			// B ¡æ A
			if (wb + wa > A)
			{
				q.push({ A, wa + wb - A, wc });
			}
			else
			{
				q.push({ wa + wb, 0, wc });
			}

			// B ¡æ C
			if (wb + wc > C)
			{
				q.push({ wa, wb + wc - C, C });
			}
			else
			{
				q.push({ wa, 0, wb + wc});
			}

			// C ¡æ A
			if (wc + wa > A)
			{
				q.push({A, wb, wa + wc - A});
			}
			else
			{
				q.push({wa + wc, wb, 0});
			}

			// C ¡æ B
			if (wc + wb > B)
			{
				q.push({ wa, B, wb + wc - B });
			}
			else
			{
				q.push({ wa, wb + wc, 0 });
			}
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &A, &B, &C);

	BFS();

	for (int i = 0; i <= C; i++)
	{
		if (water[i]) printf("%d ", i);
	}

	printf("\n");

	return 0;
}