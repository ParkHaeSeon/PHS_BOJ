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

int N = 0;

int main(void)
{
	string s;

	while (1)
	{
		getline(cin, s);

		if (s.compare("END") == 0) break;

		reverse(s.begin(), s.end());

		cout << s << '\n';
	}

	return 0;
}