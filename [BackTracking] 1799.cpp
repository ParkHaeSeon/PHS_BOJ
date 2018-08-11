#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

/*

For example,

My chess bishop solution is 

  0 1 2 3 4 5 6 7 . .
0 B W B W B W B W . .

1 W B W B W B W B . . 

2 B W B W B W B W . .

3 W B W B W B W B . .

*/

int N = 0;

int chess[11][11] = { 0, };

bool diagonalline[2][22] = { false, };

int ans[2] = { 0, };

int color = 0;

void DFS(int row, int column, int Cnt)
{
	ans[color] = max(ans[color], Cnt);

	if (column >= N)
	{
		++row; // row(y) plus

		if (row % 2 == 0) // if even row
		{
			if (color == 0) // if black
			{
				column = 0; // column is zero
			}
			else // if white
			{
				column = 1; // column is one
			}
		}
		else // if odd row
		{
			if (color == 0) // if black
			{
				column = 1; // column is one
			}
			else // if white
			{
				column = 0; // column is zero
			}
		}
	}

	if (row >= N) return;

	if (chess[row][column] == 1 && !diagonalline[0][row + column] && !diagonalline[1][N + row - column])
	{
		diagonalline[0][row + column] = true;
		diagonalline[1][N + row - column] = true;

		DFS(row, column + 2, Cnt + 1); // 비숍을 놓는 케이스

		diagonalline[0][row + column] = false;
		diagonalline[1][N + row - column] = false;
	}
	
	DFS(row, column + 2, Cnt); // 비숍을 놓지 않는 케이스
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &chess[i][j]);
		}
	}
	color = 0;

	DFS(0, 0, 0); // 0 : black, (y:0, x:0) start

	color = 1;

	DFS(0, 1, 0); // 1 : white, (y:0, x:1) start

	printf("%d\n", ans[0] + ans[1]);

	return 0;
}