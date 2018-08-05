#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int map[21][21] = { 0, };

int N = 0; // 세로
int M = 0; // 가로
int dice_start_y = 0; // 주사위를 놓을 곳의 좌표 : 행
int dice_start_x = 0; // 주사위를 놓을 곳의 좌표 : 열
int K = 0; // 명령의 개수
int dice[7] = { 0, };
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int ny = 0, nx = 0;

void diceUpdate(int input_move)
{
	int temp[7] = { 0, };

	if (input_move == 1) // 동
	{
		for (int i = 1; i <= 6; i++)
		{
			temp[i] = dice[i];
		}

		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (input_move == 2) // 서
	{
		for (int i = 1; i <= 6; i++)
		{
			temp[i] = dice[i];
		}

		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	else if (input_move == 3) // 북
	{
		for (int i = 1; i <= 6; i++)
		{
			temp[i] = dice[i];
		}

		dice[1] = temp[5];
		dice[2] = temp[1];
		dice[5] = temp[6];
		dice[6] = temp[2];
	}
	else if (input_move == 4) // 남
	{
		for (int i = 1; i <= 6; i++)
		{
			temp[i] = dice[i];
		}

		dice[1] = temp[2];
		dice[2] = temp[6];
		dice[5] = temp[1];
		dice[6] = temp[5];
	}
}

void mapCheck()
{
	if (map[dice_start_y][dice_start_x] == 0)
	{
		map[dice_start_y][dice_start_x] = dice[1];
	}
	else if (map[dice_start_y][dice_start_x] != 0)
	{
		dice[1] = map[dice_start_y][dice_start_x];

		map[dice_start_y][dice_start_x] = 0;
	}
}

int main(void)
{
	int x = 0;

	memset(dice, 0, sizeof(dice));

	scanf("%d %d %d %d %d", &N, &M, &dice_start_y, &dice_start_x, &K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	
	while (K--)
	{
		scanf("%d", &x);

		ny = dice_start_y + dy[x - 1];

		nx = dice_start_x + dx[x - 1];
	
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

		dice_start_y = ny;

		dice_start_x = nx;

		diceUpdate(x);

		mapCheck();

		printf("%d ", dice[6]);
	}

	printf("\n");

	return 0;
}