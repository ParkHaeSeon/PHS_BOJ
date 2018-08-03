#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int F = 0; // �ǹ��� �� F��
int S = 0; // ���� �ִ� �� S
int G = 0; // ������ ��
int U = 0; // ���� U��ŭ �̵�
int D = 0; // �Ʒ��� D��ŭ �̵�

int visit[1000001] = { 0, };

/*
10 1 10 2 1 �� 6
���� 1 ���� : �ǹ��� �� 10���̰�, ���� �ִ� ���� 1���̴�. 
�׸��� �������� 10���̰�, ���������ʹ� ���� 2��, �Ʒ��� 1�� ��ŭ �̵��� �� �ִ�.
1 -> 3 -> 5 -> 7 -> 9 -> 8 -> 10
*/

queue<pair<int, int> > q;

int BFS()
{
	q.push(make_pair(S, 0));

	visit[S] = 1;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int here = q.front().first;
			int cnt = q.front().second;

			q.pop();

			if (here == G)
			{
				return cnt;
			}

			if (here + U <= 1000000 && visit[here + U] == -1)
			{
				q.push(make_pair(here + U, cnt + 1));
				visit[here + U] = 1;
			}

			if (here - D >= 1 && visit[here - D] == -1)
			{
				q.push(make_pair(here - D, cnt + 1));
				visit[here - D] = 1;
			}
		}
	}

	return -1;
}

int main(void)
{
	memset(visit, -1, sizeof(visit));

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	int ans = BFS();

	if (ans == -1) printf("use the stairs\n");
	else printf("%d\n", ans);

	return 0;
}