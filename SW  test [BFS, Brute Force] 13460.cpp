/*
백준 13460번 구슬 탈출 2

[문제]
스타트링크에서 판매하는 어린이용 장남감 중에서 가장 인기가 많은 제품은 구슬 탈출이다.
구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.

보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다.
가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다.
빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이 때, 파란 구슬이 구멍에 들어가면 안된다.

이 때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다.
왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

각각의 동작에서 공은 동시에 움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다.
빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다.

또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

[입력 1]
5 5
#####
#..B#
#.#.#
#RO.#
#####
[출력 1]
1

[입력 2]
7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######
[출력 2]
5

[입력 3]
7 7
#######
#..R#B#
#.#####
#.....#
#####.#
#O....#
#######
[출력 3]
5

[입력 4]
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#6
#......#.#
#.######.#
#.#....#.#
#.#.#.#..#
#...#.O#.#
##########
[출력 4]
-1

[입력 5]
3 7
#######
#R.O.B#
#######
[출력 5]
1

[입력 6]
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.##...#
#O..#....#
##########
[출력 6]
7

[입력 7]
3 10
##########
#.O....RB#
##########
[출력 7]
-1
*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N = 0; // 세로 = y = N
int M = 0; // 가로 = x = M

int visit[11][11][11][11];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int ry, rx, by, bx;

char map[11][11];

queue<pair<pair<int, int>, pair<int, int> > > q;

int BFS()
{
	q.push(make_pair(make_pair(ry, rx), make_pair(by, bx)));

	visit[ry][rx][by][bx] = 1;

	int Cnt = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		for (int i = 0; i < qSize; i++)
		{
			int Ry = q.front().first.first;
			int Rx = q.front().first.second;

			int By = q.front().second.first;
			int Bx = q.front().second.second;

			q.pop();

			if (map[Ry][Rx] == 'O' && map[Ry][Rx] != map[By][Bx])
			{
				return Cnt;
			}
			
			for (int j = 0; j < 4; j++)
			{
				int RedY = Ry;
				int RedX = Rx;
				int BlueY = By;
				int BlueX = Bx;

				while (map[RedY + dy[j]][RedX + dx[j]] != '#' && map[RedY][RedX] != 'O')
				{
					//printf("레드 - Y : %d, X : %d\n", RedY, RedX);
					RedY += dy[j];
					RedX += dx[j];
				}

				while (map[BlueY + dy[j]][BlueX + dx[j]] != '#' && map[BlueY][BlueX] != 'O')
				{
					//printf("블루 - Y : %d, X : %d\n", BlueY, BlueX);
					BlueY += dy[j];
					BlueX += dx[j];
				}

				if (RedY == BlueY && RedX == BlueX)
				{
					if (map[RedY][RedX] == 'O') continue;

					if (abs(RedY - Ry) + abs(RedX - Rx) < abs(BlueY - By) + abs(BlueX - Bx))
					{
						BlueY -= dy[j];
						BlueX -= dx[j];
					}
					else
					{
						RedY -= dy[j];
						RedX -= dx[j];
					}
				}

				if (visit[RedY][RedX][BlueY][BlueX] == 1) continue;
				
				q.push(make_pair(make_pair(RedY, RedX), make_pair(BlueY, BlueX)));

				visit[RedY][RedX][BlueY][BlueX] = 1;
			}
		}

		if (Cnt >= 10) return -1;

		++Cnt;
	}

	return -1;
}

int main(void)
{
	scanf("%d %d", &N, &M); // 세로 N, 가로 M

	for (int i = 1; i <= N; i++) // 세로 y
	{
		getchar();

		for (int j = 1; j <= M; j++) // 가로 x
		{
			scanf("%c", &map[i][j]);

			if (map[i][j] == 'R')
			{
				ry = i;
				rx = j;
			}
			else if (map[i][j] == 'B')
			{
				by = i;
				bx = j;
			}
		}
	}

	printf("%d\n", BFS());

	return 0;
}
