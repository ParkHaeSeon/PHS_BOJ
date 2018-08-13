#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

deque<int> dq[5];

int N = 0;

/*

ȸ�� ��Ų ��� ������ 1���̶��,
1. 2�� �˻� �� 3�� �˻� �� 4�� �˻�

ȸ�� ��Ų ��� ������ 2���̶��,
1. 1�� �˻�
2. 3�� �˻� �� 4�� �˻�

ȸ�� ��Ų ��� ������ 3���̶��,
1. 2�� �˻� �� 1�� �˻�
2. 4�� �˻�

ȸ�� ��Ų ��� ������ 4���̶��,
1. 3�� �˻� �� 2�� �˻� �� 1�� �˻�

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

int Rotate_Check_decrease(int gear, int clock)
{
	//if (dq[gear][2] == dq[gear + 1][6]) return 0;

	if (clock == 1)
	{
		onlyRotate(gear, -1);

		return - 1;
	}
	else if (clock == -1)
	{
		onlyRotate(gear, 1);

		return 1;
	}
}

int Rotate_Check_increase(int gear, int clcok)
{
	//if (dq[gear - 1][2] == dq[gear][6]) return 0;

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

void Rotate_Gear(int gear, int clock)
{
	int left = dq[gear][6];
	int right = dq[gear][2];

	if (clock == 1) // clockwise
	{
		dq[gear].push_front(dq[gear].back());

		dq[gear].pop_back();

		if (gear == 1) // �� 1�� ��
		{
			if (right == dq[gear + 1][6]) return;
			// 1�� �����ʰ� 2�� ������ ������ ����


			int r = dq[gear + 1][2];
			// 2�� ������ ����


			int var = Rotate_Check_increase(2, clock);
			// 2 ȸ��


			if (r == dq[3][6]) return;
			// 2�� �����ʰ� 3�� ������ ������ ����

			r = dq[gear + 2][2];
			// r�� 3�� ������ ����

			var = Rotate_Check_increase(3, var);

			if (r == dq[4][6]) return;
			// 3�� �����ʰ� 4�� ������ ������ ����

			Rotate_Check_increase(4, var);
		}
		else if (gear == 2)
		{
			if (left != dq[gear - 1][2])
			{
				onlyRotate(1, -clock);
			}

			if (right == dq[gear + 1][6]) return;
			// 2�� �����ʰ� 3�� ������ ������ ����

			int r = dq[3][2];
			// 3�� ������ ����

			int var = Rotate_Check_increase(3, clock);

			if ( r == dq[4][6]) return;
			// 3�� == 4�� ����

			Rotate_Check_increase(4, var);
		}
		else if (gear == 3)
		{
			if (right != dq[gear + 1][6])
			{
				onlyRotate(4, -clock);
			}

			if (left == dq[gear - 1][2]) return;
			// 3�ް� 2���� ������ ����

			int l = dq[gear-1][6];
			// 2�� ����

			int var = Rotate_Check_decrease(2, clock);

			if(l == dq[1][2]) return;
			// 2�ް� 1���� ������ ����

			Rotate_Check_decrease(1, var);
		}
		else if (gear == 4)
		{
			if (left == dq[gear - 1][2]) return;
			// 4�ް� 3���� ������ ����

			int l = dq[3][6];
			// 3�� ���� ����

			int var = Rotate_Check_decrease(3, clock);

			if (l == dq[2][2]) return;
			// 3�ް� 2���� �����餩����

			l = dq[2][6];
			// 2�� ����
			var = Rotate_Check_decrease(2, clock);

			if (l == dq[1][2]) return;

			Rotate_Check_decrease(1, clock);
		}
	}
	else if (clock == -1) // counterclockwise
	{
		dq[gear].push_back(dq[gear].front());

		dq[gear].pop_front();

		if (gear == 1) // �� 1�� ��
		{
			if (right == dq[gear + 1][6]) return;
			// 1�� �����ʰ� 2�� ������ ������ ����


			int r = dq[gear + 1][2];
			// 2�� ������ ����


			int var = Rotate_Check_increase(2, clock);
			// 2 ȸ��


			if (r == dq[3][6]) return;
			// 2�� �����ʰ� 3�� ������ ������ ����

			r = dq[gear + 2][2];
			// r�� 3�� ������ ����

			var = Rotate_Check_increase(3, var);

			if (r == dq[4][6]) return;
			// 3�� �����ʰ� 4�� ������ ������ ����

			Rotate_Check_increase(4, var);
		}
		else if (gear == 2)
		{
			if (left != dq[gear - 1][2]) // 1�����ʰ� 2�� �������� ���� �ʴٸ� ����
			{
				
				onlyRotate(1, -clock);
			}

			if (right == dq[gear + 1][6]) return;
			// 2�� �����ʰ� 3�� ������ ������ ����

			int r = dq[3][2];
			// 3�� ������ ����

			int var = Rotate_Check_increase(3, clock);

			if (r == dq[4][6]) return;
			// 3�� == 4�� ����

			Rotate_Check_increase(4, var);
		}
		else if (gear == 3)
		{
			if (right != dq[gear + 1][6])
			{
				onlyRotate(4, -clock);
			}

			if (left == dq[gear - 1][2]) return;
			// 3�ް� 2���� ������ ����

			int l = dq[gear - 1][6];
			// 2�� ����

			int var = Rotate_Check_decrease(2, clock);

			if (l == dq[1][2]) return;
			// 2�ް� 1���� ������ ����

			Rotate_Check_decrease(1, var);
		}
		else if (gear == 4)
		{
			if (left == dq[gear - 1][2]) return;
			// 4�ް� 3���� ������ ����

			int l = dq[3][6];
			// 3�� ���� ����

			int var = Rotate_Check_decrease(3, clock);

			if (l == dq[2][2]) return;
			// 3�ް� 2���� �����餩����

			l = dq[2][6];
			// 2�� ����
			var = Rotate_Check_decrease(2, clock);

			if (l == dq[1][2]) return;

			Rotate_Check_decrease(1, clock);
		}
	}
}



int main(void)
{
	// N : 0, S : 1

	// clockwise : 1, counterclockwise : -1

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

	int var = rotation_count;

	while (var--)
	{
		scanf("%d %d", &gearNumber, &clockVector);

		Rotate_Gear(gearNumber, clockVector);

		//printf("\n==(%d, %d)==\n", gearNumber, clockVector);

		//for (int i = 1; i <= 4; i++)
		//{
		//	for (int j = 0; j < 8; j++)
		//	{
		//		printf("%d", dq[i][j]);
		//	}

		//	printf("\n");
		//}
	}

	for (int i = 1; i <= 4; i++)
	{
		int score = dq[i].front();

		//printf("%d�� ° ��Ϲ��� �� �� : %d\n", i, dq[i].front());

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