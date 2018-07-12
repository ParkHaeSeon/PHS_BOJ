#include <cstdio>
#include <iostream>

using namespace std;

int N = 0; // 사람 수
int M = 0; // 양의 정수
int K = 0;

int num[5001] = { 0, };

int main(void)
{
	scanf("%d %d", &N, &M);

	K = M - 1;

	for (int i = 0; i < N; i++)
	{
		num[i] = i + 1;
	}

	printf("<%d", num[K]);

	for (; N > 1; N--)
	{
		for (int j = K; j < N; j++)
		{
			num[j] = num[j + 1];
		}

		--K;

		K = (K + M) % (N - 1);

		printf(", %d", num[K]);
	}
	
	printf(">\n");

	return 0;
}