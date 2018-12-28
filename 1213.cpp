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

int alpha[91] = { 0, };

int main(void)
{
	string s;

	vector<char> v;

	cin >> s;

	for (int i = 0; i < s.length(); i++)
		++alpha[s[i]];

	int odd = 0;

	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (alpha[i] % 2 != 0) ++odd;
	}

	if (odd > 1)
	{
		printf("I'm Sorry Hansoo\n");
		return 0;
	}

	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (alpha[i] == 0) continue;

		int chance = alpha[i];

		if (alpha[i] % 2 != 0) --chance;

		int cnt = 1;

		for (int j = 0; j < chance; j++)
		{
			if (cnt == 1)
			{
				v.insert(v.begin(), i);

				cnt = -1;
			}
			else if (cnt == -1)
			{
				v.push_back(i);

				cnt = 1;
			}

			--alpha[i];
		}
	}

	for (int i = 'A'; i <= 'Z'; i++)
		if (alpha[i] == 1) v.insert(v.begin() + v.size() / 2, i);

	for (auto i : v) printf("%c", i);
	printf("\n");

	return 0;
}
