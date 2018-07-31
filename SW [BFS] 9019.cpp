#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[10001] = { 0, };

int A = 0;
int B = 0;

string BFS()
{
	queue<pair<int, string> > q;

	string s;

	q.push(make_pair(A, ""));

	visit[A] = 1;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int start = q.front().first;

			string result = q.front().second;

			if (start == B)
			{
				return result;
			}

			q.pop();

			// D
			int Dn = (2 * start) % 10000;
			if (visit[Dn] == 0)
			{
				q.push(make_pair(Dn, result + "D"));
				visit[Dn] = 1;
			}

			// S
			int Sn = start - 1 < 0 ? 9999 : start - 1;

			if (visit[Sn] == 0)
			{
				q.push(make_pair(Sn, result + "S"));
				visit[Sn] = 1;
			}

			// L
			int Ln = (start % 1000)*10 + start/1000;
			if (Ln >= 0 && Ln < 10000 && visit[Ln] == 0)
			{
				q.push(make_pair(Ln, result + "L"));
				visit[Ln] = 1;
			}

			// R
			int Rn = (start % 10) * 1000 + start / 10;
			if (Rn >=0 && Rn < 10000 && visit[Rn] == 0)
			{
				q.push(make_pair(Rn, result + "R"));
				visit[Rn] = 1;
			}
		}
	}
}

int main(void)
{
	int T = 0;;

	scanf("%d", &T);

	for(int i=0; i<T; i++)
	{
		scanf("%d %d", &A, &B);

		memset(visit, 0, sizeof(visit));

		cout << BFS() << endl;
	}

	return 0;
}