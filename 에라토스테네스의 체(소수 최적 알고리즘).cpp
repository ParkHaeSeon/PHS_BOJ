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
		// 입력받은 num만큼 배열에 초기화

		arr[i] = i;

		/*
		예)
		arr[2] = 2;
		arr[3] = 3;
		.
		.
		arr[num] = num;
		*/
	}

	int sqrtnum = sqrt(num); // 기본적인 최적화를 하려면, 함수에서 함수를 쓰지 않는다.

	for (int i = 2; i <= sqrtnum; i++)
	{
		if (arr[i] == 0) continue; // 이미 아래에서 체크한 수의 배수는 확인하지 않는다.

		for (int j = 2 * i; j <= num; j += i) // i를 제외한 i의 배수들은 0으로 체크한다.
		{
			arr[j] = 0;

			/*
			예)
			i가 2일 때, j=4부터 입력받은 num까지 2씩 증가하면서 0으로 초기화.
			→ arr[4] = 0, ...

			i가 3일 때, j=6부터 입력받은 num까지 3씩 증가하면서 0으로 초기화.
			→ arr[6] = 0, ...

			.
			.
			.
			.

			*/
		}
	}

	for (int i = 2; i < num; i++)
	{
		if (arr[i] == 0) continue; // 소수가 아닐 경우 무시(continue)

		printf("%d\n", arr[i]); // 소수이면 출력
	}
}

int main(void)
{
	int num = 0;

	scanf("%d", &num); // input a number

	getChe(num); // transfer function

	return 0;
}