#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

queue<pair<int, int> > q;

int visit[101][101] = { 0, };
int n[101][101] = { 0, };
int N = 0;
int M = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int BFS(int y, int x)
{
	int count = 1;

	visit[y][x] = 1;

	q.push(make_pair(y, x));

	while (!q.empty())
	{
		int qSize = q.size();

		for (int size = 0; size < qSize; size++)
		{
			int qy = q.front().first;
			int qx = q.front().second;

			q.pop();

			if (qx == M && qy == N) return count; // 이거 반드시 있어야함.

			for (int index = 0; index < 4; index++)
			{
				int Y = qy + dy[index];
				int X = qx + dx[index];

				if ( 1<= X && X <= M  && 1<=Y && Y<=N && (n[Y][X] == 1) && (visit[Y][X] == 0))
				{

					visit[Y][X] = 1;

					q.push(make_pair(Y, X));
					
				}
			}
		}

		++count;
	}

	return count;
}

int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) // N=y=i=세로
	{
		for (int j = 1; j <= M; j++) // M=x=j=가로
		{
			scanf("%1d", &n[i][j]);
		}
	}
	
	printf("%d\n", BFS(1, 1));

	return 0;
}



/*

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>


using namespace std;

int MAP[101][101] = { 0, };

int N, M;

queue<pair<int, int> > q;

int find_path();

bool visit[101][101] = { false , };

int find_path()
{
	int count = 1;
	int x = 1, y = 1;
	int size = 0;

	visit[1][1] = true;

	q.push(make_pair(1, 1));

	while (!q.empty())
	{
		size = q.size();
		
		for (int i = 0; i < size; i++)
		{

			y = q.front().first;
			x = q.front().second;

			q.pop();

			if (x == M && y == N)
			{
				return count;
			}


			if ( x+1 <= M && !visit[y][x + 1] && MAP[y][x + 1])
			{
				q.push(make_pair(y, x + 1));

				visit[y][x + 1] = true;
			}

			if (y+1 <= N && !visit[y+1][x] && MAP[y+1][x])
			{
				q.push(make_pair(y+1, x));

				visit[y+1][x] = true;
			}

			if (y-1 >= 0 && !visit[y-1][x] && MAP[y-1][x])
			{
				q.push(make_pair(y - 1, x));

				visit[y-1][x] = true;
			}

			if (x-1 >= 0 && !visit[y][x-1] && MAP[y][x-1])
			{
				q.push(make_pair(y, x-1));

				visit[y][x-1] = true;
			}
		}

		++count;
		
	}

	return count;
}

int main(void)
{
	int path;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{	
			scanf("%1d", &MAP[i][j]);
		}
	}

	printf("%d\n", find_path());

	return 0;
}

*/
