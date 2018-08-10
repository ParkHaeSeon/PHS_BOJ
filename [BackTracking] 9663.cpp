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

		// ���⼭�� row�� column �� �� �ϳ��� �־ �ȴ�. 
		// ��, �밢�� 2�� <- �̰͸� ���� �Ͽ���.
		// �� : N + pos-i(pos-i�� �����ϴ�. �׷��� pos-i�� ������ �� �� �ֱ� ������, N���� ������ ���ش�.)
		// �� : pos + i�� ������ ����� ���´�.
	}
}

int main(void)
{
	scanf("%d", &N);

	DFS(0);

	printf("%d\n", result);

	return 0;
}