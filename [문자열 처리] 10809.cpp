#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;

// https://www.acmicpc.net/problem/10809

int main(void)
{
	int pos = 0;

	getline(cin, s);

	for (int i = 'a'; i <= 'z'; i++)
	{
		auto it = find(s.begin(), s.end(), i);

		if (it == s.end()) printf("-1 ");
		else cout << it-s.begin() << " ";
	}

	printf("\n");

	return 0;
}
