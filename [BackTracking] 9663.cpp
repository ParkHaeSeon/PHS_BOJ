#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N = 0;

int result = 0;

bool row[16] = { false, };

bool column[16] = { false, };

bool diagonalline_1[32] = { false, };

bool diagonalline_2[32] = { false, };

void DFS(int pos)
{
	if (pos == N)
	{
		++result;
		return;
	}

	for (int i = 0; i < N; i++) // i is x(column) and pos is y(row) 
	{
		if (row[i] || column[i] || diagonalline_1[pos + i] || diagonalline_2[N + pos - i]) continue;

		row[i] = true;
		column[i] = true;
		diagonalline_1[pos + i] = true;
		diagonalline_2[N + pos - i] = true;

		DFS(pos + 1);

		row[i] = false;
		column[i] = false;
		diagonalline_1[pos + i] = false;
		diagonalline_2[N + pos - i] = false;

		// 여기서는 row나 column 둘 중 하나만 있어도 된다. 
		// 열, 대각선 2개 <- 이것만 구현 하였음.
		// ↘ : N + pos-i(pos-i가 일정하다. 그러나 pos-i는 음수가 될 수 있기 때문에, N으로 보정을 해준다.)
		// ↙ : pos + i가 일정한 상수를 갖는다.
	}
}

int main(void)
{
	scanf("%d", &N);

	DFS(0);

	printf("%d\n", result);

	return 0;
}