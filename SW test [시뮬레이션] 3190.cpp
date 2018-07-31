#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define APPLE 5
#define SNAKE 6
#define LAND 0

using namespace std;

int visit[101][101] = { 0, };

int map[101][101] = { 0, };

int N = 0; // ������ ũ��(���� = ����)
int K = 0; // ����� ����
int L = 0; // ���� ���� ��ȯ Ƚ��
int Sy = 1, Sx = 1; // �� �ʱ� ��ġ
int direction = RIGHT; // �ʱ� �̵� ����
int sec = 0; // ��

deque<pair<int, int> > dq; // �� �Ӹ�, ����

void move()
{
	if (Sy <= 0 || Sy > N || Sx <= 0 || Sx > N || map[Sy][Sx] == SNAKE)
	{
		printf("%d\n", sec);
		exit(0);
	}

	if (map[Sy][Sx] == APPLE)
	{
		map[Sy][Sx] = SNAKE;
		dq.push_front(make_pair(Sy, Sx));
	}
	else if (map[Sy][Sx] == LAND)
	{
		map[Sy][Sx] = SNAKE;
		dq.push_front(make_pair(Sy, Sx));
		map[dq.back().first][dq.back().second] = LAND;
		dq.pop_back();
	}
}

int main(void)
{
	int ai = 0, aj = 0;
	int X = 0;
	char C;

	scanf("%d", &N); // ������ ũ��
	scanf("%d", &K); // ����� ����

	memset(map, LAND, sizeof(map));

	dq.push_back(make_pair(Sy, Sx));

	map[1][1] = SNAKE;

	while (K--)
	{
		scanf("%d %d", &ai, &aj);

		map[ai][aj] = APPLE;
	}

	scanf("%d", &L); // ���� ���� ��ȯ Ƚ��

	int timeMinus = 0;

	while (L--)
	{
		scanf("%d %c", &X, &C);

		int time = X;

		char cur_Pos = C;

		X -= timeMinus; // �Է��� X�� ���� �ð� ����. ��) ó�� �Է� 2, ���� �Է� 4 -> 2��

		while (X--)
		{
			++sec;

			if (direction == UP)
			{
				--Sy;
				move();
			}
			else if (direction == DOWN)
			{
				++Sy;
				move();
			}
			else if (direction == LEFT)
			{
				--Sx;
				move();
			}
			else if (direction == RIGHT)
			{
				++Sx;
				move();
			}
		}

		timeMinus = time;

		if (direction == UP && cur_Pos == 'L')
		{
			direction = LEFT;
		}
		else if (direction == UP && cur_Pos == 'D')
		{
			direction = RIGHT;
		}
		else if (direction == DOWN && cur_Pos == 'L')
		{
			direction = RIGHT;
		}
		else if (direction == DOWN && cur_Pos == 'D')
		{
			direction = LEFT;
		}
		else if (direction == LEFT && cur_Pos == 'L')
		{
			direction = DOWN;
		}
		else if (direction == LEFT && cur_Pos == 'D')
		{
			direction = UP;
		}
		else if (direction == RIGHT && cur_Pos == 'L')
		{
			direction = UP;
		}
		else if (direction == RIGHT && cur_Pos == 'D')
		{
			direction = DOWN;
		}
	}

	while (1)
	{
		++sec;

		if (direction == UP)
		{
			--Sy;
			move();
		}
		else if (direction == DOWN)
		{
			++Sy;
			move();
		}
		else if (direction == LEFT)
		{
			--Sx;
			move();
		}
		else if (direction == RIGHT)
		{
			++Sx;
			move();
		}
	}

	printf("%d\n", sec);

	return 0;
}