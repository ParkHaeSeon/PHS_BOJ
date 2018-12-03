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

int digit(string s)
{
	int sum = 0;

	for (int i = 0; i < s.length(); i++)
	{
		sum += s[i] - '0';
	}

	if (sum < 10) return sum;
	else return digit(to_string(sum));
	// else digit(to_string(sum)); 이 아니다. 주의하자.
}

int main(void)
{
	string s;

	while (1)
	{
		cin >> s;

		if (s[0] == '0') break;

		cout << digit(s) << '\n';
	}

	return 0;
}