#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

int N = 0, M = 0;

void getChe(int num)
{
	int *arr;

	arr = (int *)malloc(sizeof(int) * num); // Dynamic allocation

	for (int i = 2; i <= num; i++)
	{
		// �Է¹��� num��ŭ �迭�� �ʱ�ȭ

		arr[i] = i;

		/*
		��)
		arr[2] = 2;
		arr[3] = 3;
		.
		.
		arr[num] = num;
		*/
	}

	int sqrtnum = sqrt(num); // �⺻���� ����ȭ�� �Ϸ���, �Լ����� �Լ��� ���� �ʴ´�.

	for (int i = 2; i <= sqrtnum; i++)
	{
		if (arr[i] == 0) continue; // �̹� �Ʒ����� üũ�� ���� ����� Ȯ������ �ʴ´�.

		for (int j = 2 * i; j <= num; j += i) // i�� ������ i�� ������� 0���� üũ�Ѵ�.
		{
			arr[j] = 0;

			/*
			��)
			i�� 2�� ��, j=4���� �Է¹��� num���� 2�� �����ϸ鼭 0���� �ʱ�ȭ.
			�� arr[4] = 0, ...

			i�� 3�� ��, j=6���� �Է¹��� num���� 3�� �����ϸ鼭 0���� �ʱ�ȭ.
			�� arr[6] = 0, ...

			.
			.
			.
			.

			*/
		}
	}

	for (int i = 2; i < num; i++)
	{
		if (arr[i] == 0) continue; // �Ҽ��� �ƴ� ��� ����(continue)

		printf("%d\n", arr[i]); // �Ҽ��̸� ���
	}
}

int main(void)
{
	int num = 0;

	scanf("%d", &num); // input a number

	getChe(num); // transfer function

	return 0;
}