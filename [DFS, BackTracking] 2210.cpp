#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int digit[5][5] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int ans = 0;

bool visit[1000000] = { false, };

void DFS(int r, int c, string numstring, int cnt)
{
	if (cnt == 5)
	{
		int n = 0;

		n = stoi(numstring);

		if (!visit[n])
		{
			++ans;
			visit[n] = true;
		}

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int y = r + dy[i];
		int x = c + dx[i];

		if (0 <= y && y < 5 && 0 <= x && x < 5)
		{
			string s, t;

			s = (char)(digit[y][x] + '0');

			t = numstring;

			numstring += s;

			DFS(y, x, numstring, cnt + 1);

			numstring  = t;
		}
	}
}

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> digit[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			string s;

			s += (char)(digit[i][j] + '0');

			DFS(i, j, s, 0);		
		}
	}

	cout << ans << endl;

	return 0;
}
