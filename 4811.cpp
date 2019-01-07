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

long long a[31][31] = { 0, };

long long search(int w, int h)
{
	if (w < 0) return 0;

	if (a[w][h] > 0) return a[w][h];

	if (w == 0 && h == 0) return 1;

	if (w > 0) a[w][h] += search(w - 1, h + 1);	

	if (h > 0) a[w][h] += search(w, h - 1);

	return a[w][h];
}

int main(void)
{
	int N = 0;

	while (1)
	{
		scanf("%d", &N);

		if (N == 0) break;

		cout << search(N, 0) << '\n';
	}

	return 0;
}