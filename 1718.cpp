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

int main(void)
{
	string e, s;

	getline(cin, e); // ��
	getline(cin, s); // ��ȣȭ Ű

	int p = 0, a = 0;

	while(p < e.length()) // ��
	{
		if (a == s.length()) a = 0;

		if (e.at(p) == ' ')
		{
			printf(" ");
			++p;
			++a;
			continue;
		}

		int First = (int)e.at(p); // ��
		int Second = (int)s.at(a); // ��ȣȭŰ

		int diff = abs(First - Second);

		int move = Second - 'a' + 1;

		if (First - move < 97) printf("%c", char('z' - diff));
		else printf("%c", char(First - move));

		++p;
		++a;	
	}

	printf("\n");

	return 0;
}