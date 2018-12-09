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

bool num[1000] = { false, };

void Chk(int f, int s, int t, int strike, int ball)
{
	for (int i = 100; i <= 999; i++)
	{
		int nstrike = 0, nball = 0;

		if (num[i])
		{
			int nf = i / 100;
			int ns = (i % 100) / 10;
			int nt = (i % 100) % 10;

			if (f == nf) ++nstrike;
			if (s == ns) ++nstrike;
			if (t == nt) ++nstrike;

			if (f != nf && (f == ns || f == nt)) ++nball;
			if (s != ns && (s == nf || s == nt)) ++nball;
			if (t != nt && (t == nf || t == ns)) ++nball;

			if (nstrike != strike || nball != ball) num[i] = false;
		}
	}
}

int main(void)
{
	int N = 0, input = 0, strike = 0, ball = 0;

	memset(num, true, sizeof(num));
	// 일단 모두 된다고 가정

	for (int i = 100; i <= 999; i++)
	{
		int f = i / 100;
		int s = (i % 100) / 10;
		int t = (i % 100) % 10;

		if (f == s || s == t || t == f)
		{
			num[i] = false;
		}

		if (f == 0 || s == 0 || t == 0)
		{
			num[i] = false;
		}
	}

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int f = 0, s = 0, t = 0;

		scanf("%1d%1d%1d", &f, &s, &t);
		scanf("%d %d", &strike, &ball);

		Chk(f, s, t, strike, ball);
	}

	int result = 0;

	for (int i = 100; i <= 999; i++)
	{
		if (num[i]) ++result;
	}

	printf("%d\n", result);

	return 0;
}