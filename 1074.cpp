#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

int r = 0, c = 0, result = 0;

void search(int N, int y, int x, int go)
{
	if (y == r && x == c)
	{
		printf("%d\n", result);

		exit(0);
	}

	if ((y <= r && r < y + go) && (x <= c && c < x + go))
	{
		// Z ���� ������ �湮.

		search(N / 2, y, x, go / 2); // �� ����
		search(N / 2, y, x + go / 2, go / 2); // �� ������
		search(N / 2, y + go / 2, x, go / 2); // �Ʒ� ����
		search(N / 2, y + go / 2, x + go / 2, go / 2); // �Ʒ� ������
	}
	else result += go*go;

	return;
}

int main(void)
{
	int N = 0;

	scanf("%d %d %d", &N, &r, &c);

	N = (int)pow(2, N);

	search(N, 0, 0, N);

	return 0;
}