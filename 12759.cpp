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

int Map[4][4] = { 0, };

int start = 0;

bool stop = false;

int isFinished(int turn)
{
	int ret = 0;

	// 행
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] != turn) break;

			if (j == 2) return turn;
		}
	}

	// 열
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (Map[i][j] != turn) break;

			if (i == 2) return turn;
		}
	}

	// 오른쪽 아래 대각선
	for (int i = 0; i < 3; i++)
	{
		if (Map[i][i] != turn) break;

		if (i == 2) return turn;	
	}

	// 왼쪽 아래 대각선
	for (int i = 0; i < 3; i++)
	{
		if (Map[i][2 - i] != turn) break;

		if (i == 2) return turn;	
	}

	return 0;
}

int main(void)
{
	int r = 0, c = 0, win = 0, next = 0;

	scanf("%d", &start);

	for(int i=0; i<9; i++)
	{
		if (i % 2 == 0) next = start;
		else
		{
			if (start == 2) next = 1;		
			else next = 2;
		}

		scanf("%d %d", &r, &c);

		--r; --c;

		Map[r][c] = next;	

		if (!stop)
		{
			win = isFinished(next);

			if (win != 0) stop = true;
		}
	}

	printf("%d\n", win);

	return 0;
}