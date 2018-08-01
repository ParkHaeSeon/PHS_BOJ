#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N = 0; // �������� ����

long long B = 0; // �Ѱ������� �� �濡�� ������ �� �ִ� �������� ��
long long C = 0; // �ΰ������� �� �濡�� ������ �� �ִ� �������� ��

vector<long long> A; // ������ �����忡 �ش��ϴ� �ο� ��

long long cnt = 0; // ����

void find()
{
	long long remind = 0;

	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] <= B) ++cnt;
		else
		{
			A[i] -= B;

			++cnt;

			if (A[i] > C)
			{
				if (C != 1)
				{
					if (A[i] % C == 0) cnt += A[i] / C;
					else cnt += (A[i] / C) + 1;
				}
				else cnt += A[i];
			}
			else
			{
				cnt += 1;
			}
		}
	}
}

int main(void)
{
	long long people = 0;

	scanf("%d", &N);

	while (N--)
	{
		scanf("%lld", &people);

		A.push_back(people);
	}

	scanf("%lld %lld", &B, &C);

	find();

	printf("%lld\n", cnt);

	return 0;
}