#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N = 0; // 시험장의 개수

long long B = 0; // 총감독관이 한 방에서 감시할 수 있는 응시자의 수
long long C = 0; // 부감독관이 한 방에서 감시할 수 있는 응시자의 수

vector<long long> A; // 각각의 시험장에 해당하는 인원 수

long long cnt = 0; // 정답

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