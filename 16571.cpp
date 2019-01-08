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

char Map[4][4];

bool isFinished(char turn)
{
	// 가로
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] != turn) break;

			if (j == 2) return true;
		}
	}

	// 세로
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (Map[i][j] != turn) break;

			if (i == 2) return true;
		}
	}

	// 오른쪽 아래 대각선
	for (int i = 0; i < 3; i++)
	{
		if (Map[i][i] != turn) break;

		if (i == 2) return true;
	}

	// 왼쪽 아래 대각선
	for (int i = 0; i < 3; i++)
	{
		if (Map[i][2 - i] != turn) break;

		if (i == 2) return true;
	}

	return false;
}

int backtracking(char turn)
{
	if (isFinished('x' + 'o' - turn)) return -1;

	int minValue = 2;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] == '.')
			{
				Map[i][j] = turn;

				minValue = min(minValue, backtracking('o' + 'x' - turn));

				Map[i][j] = '.';
			}
		}
	}

	if (minValue == 2 || minValue == 0) return 0;

	return -minValue;
}

int main(void)
{
	int num = 0, cnt = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &num);

			if (num == 0) Map[i][j] = '.';
			else if (num == 1) Map[i][j] = 'x';
			else if (num == 2) Map[i][j] = 'o';

			if (num != 0) ++cnt;
		}
	}

	char start = 'x';

	if (cnt % 2 != 0) start = 'o';

	switch (backtracking(start))
	{
		case -1: printf("L\n");
			break;

		case 0: printf("D\n");
			break;

		case 1: printf("W\n");
			break;

		default:
			break;
	}

	return 0;
}