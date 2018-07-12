#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;

int main(void)
{
	int len = 0;

	getline(cin, s);

	for (int i = 0; s[i]; i++)
	{
		len += 1;
	}

	printf("%d\n", len);

	return 0;
}