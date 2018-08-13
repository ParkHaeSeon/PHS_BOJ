#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

deque<int> dq[5];

int N = 0;

/*

회전 시킨 톱니 바퀴가 1번이라면,
1. 2번 검사 → 3번 검사 → 4번 검사

회전 시킨 톱니 바퀴가 2번이라면,
1. 1번 검사
2. 3번 검사 → 4번 검사

회전 시킨 톱니 바퀴가 3번이라면,
1. 2번 검사 → 1번 검사
2. 4번 검사

회전 시킨 톱니 바퀴가 4번이라면,
1. 3번 검사 → 2번 검사 → 1번 검사

*/

void onlyRotate(int gear, int clock)
{
	if (clock == 1) // clockwise
	{
		dq[gear].push_front(dq[gear].back());

		dq[gear].pop_back();
	}
	else if (clock == -1) // counterclockwise
	{
		dq[gear].push_back(dq[gear].front());

		dq[gear].pop_front();
	}
}

int Do_Rotate(int gear, int clcok)
{
	if (clcok == 1)
	{
		onlyRotate(gear, -1);

		return -1;
	}
	else if (clcok == -1)
	{
		onlyRotate(gear, 1);

		return 1;
	}
}

int gear_left(int gear)
{
	int ret = 0;

	ret = dq[gear][6];

	return ret;
}

int gear_right(int gear)
{
	int ret = 0;

	ret = dq[gear][2];

	return ret;
}

void Rotate_Gear(int gear, int clock)
{
	int left = dq[gear][6]; // 입력 받은 톱니 바퀴의 왼쪽

	int right = dq[gear][2]; // 입력 받은 톱니 바퀴의 오른쪽 

	if (clock == 1) // 시계 방향이라면
	{
		dq[gear].push_front(dq[gear].back());

		dq[gear].pop_back();
	}
	else if (clock == -1) // 반시계 방향이라면
	{
		dq[gear].push_back(dq[gear].front());

		dq[gear].pop_front();
	}

	if (gear == 1)
	{
		// 1 오 vs 2 왼
		if (right == gear_left(2)) return; // 1오와 2왼이 같다면 리턴
		int r = gear_right(2); // 다르면 2를 회전 시키기 전에 2오를 저장한다.
		int pos = Do_Rotate(2, clock); // 다르면 2회전

		// 2 오 vs 3 왼
		if (r == gear_left(3)) return; // 2오와 3왼이 같다면 리턴
		r = gear_right(3); // 다르면 3을 회전 시키기 전에 3오를 저장한다.
		pos = Do_Rotate(3, pos); // 3회전

		// 3 오 vs 4 왼
		if (r == gear_left(4)) return; // 3오와 4왼이 같다면 리턴
		Do_Rotate(4, pos); // 다르면 4회전
	}
	else if (gear == 2)
	{
		// 1 오 vs 2 왼 
		if (gear_right(1) != left) onlyRotate(1, -clock);
		
		// 2 오 vs 3 왼
		if (right == gear_left(3)) return;
		int r = gear_right(3);
		int pos = Do_Rotate(3, clock);

		// 3 오 vs 4 왼
		if (r == gear_left(4)) return;
		Do_Rotate(4, pos);
	}
	else if (gear == 3)
	{
		// 3 오 vs 4 왼
		if (right != gear_left(4)) onlyRotate(4, -clock);
		
		// 2 오 vs 3 왼
		if (gear_right(2) == left) return;
		int l = gear_left(2);
		int pos = Do_Rotate(2, clock);

		// 1 오 vs 2 왼
		if (gear_right(1) == l) return;
		Do_Rotate(1, pos);
	}
	else if (gear == 4)
	{
		// 3 오 vs 4 왼	
		if (gear_right(3) == left) return;
		int l = gear_left(3);
		int pos = Do_Rotate(3, clock);

		// 2 오 vs 3 왼
		if (gear_right(2) == l) return;
		l = gear_left(2);
		pos = Do_Rotate(2, pos);

		// 1 오 vs 2 왼
		if (gear_right(1) == l) return;
		Do_Rotate(1, pos);
	}
}

int main(void)
{
	int result = 0;
	int input_num[8] = { 0, };
	int rotation_count = 0;
	int gearNumber = 0, clockVector = 0;

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &input_num[j]);

			dq[i].push_back(input_num[j]);
		}
	}

	scanf("%d", &rotation_count);

	while (rotation_count--)
	{
		scanf("%d %d", &gearNumber, &clockVector);

		Rotate_Gear(gearNumber, clockVector);
	}

	for (int i = 1; i <= 4; i++)
	{
		int score = dq[i].front();

		if (score == 0) // N
		{
			result += 0;
		}
		else if (score == 1) // S
		{
			if (i == 3) result += i + 1;
			else if (i == 4)
			{
				result += 2 * i;
			}
			else
			{
				result += i;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
