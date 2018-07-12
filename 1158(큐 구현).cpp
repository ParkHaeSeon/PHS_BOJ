#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int N = 0; // people count
int M = 0; // plus
int K = 0;

int GoToBack = 0;

queue<int> num;
queue<int> answer;

int main(void)
{
	scanf("%d %d", &N, &M);

	K = M;

	for (int i = 1; i <= N; i++)
	{
		num.push(i);
	}

	while (!num.empty())
	{
		K = M % (num.size());

		for (int j = 1; j < M; j++)
		{
			GoToBack = num.front(); // The first number

			num.pop(); // The first number pop()

			num.push(GoToBack);  // The first number push()
		}

		answer.push(num.front());

		num.pop();
	}

	printf("<%d", answer.front());

	answer.pop();

	while (!answer.empty())
	{
		printf(", %d", answer.front());

		answer.pop();
	}

	printf(">\n");

	return 0;
}