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

char result[300010];

bool cmp(char a, char b)
{
	return a > b; // 내림차순
}

int main(void)
{
	string koo, cube;

	cin >> koo;
	sort(koo.begin(), koo.end());

	cin >> cube;
	sort(cube.begin(), cube.end(), cmp);

	int len = koo.length();

	int ks = 0, ke = (koo.length() + 1) / 2 - 1;
	int cs = 0, ce = cube.length() / 2 - 1;

	if (ke <= 0) ke = 0;
	if (ce <= 0) ce = 0;

	bool turn = true;

	int rs = 0, re = koo.length() - 1;

	for (int i = 0; i < len; i++)
	{
		if (turn)
		{
			if (koo[ks] < cube[cs]) result[rs++] = koo[ks++];
			else result[re--] = koo[ke--];
		}
		else
		{
			if (koo[ks] < cube[cs]) result[rs++] = cube[cs++];
			else result[re--] = cube[ce--];
		}

		turn = !turn;
	}

	printf("%s\n", result);

	return 0;
}