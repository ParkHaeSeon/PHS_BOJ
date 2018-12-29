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

string A, B;

int main(void)
{
	cin >> A;
	cin >> B;

	int diff = 0;

	if (A.length() == B.length())
	{
		for (int i = 0; i < A.length(); i++)
		{
			if (A.at(i) != B.at(i)) ++diff;
		}
	}
	else
	{
		diff = 100;	

		for (int i = 0; i < B.length(); i++)
		{
			int a = 0, b = i, d = 0;

			if (i + A.length() > B.length()) break;

			while (a < A.length())
			{
				if (A.at(a) != B.at(b)) ++d;
						
				++a;
				++b;			
			}
			
			diff = min(diff, d);
		}
	}

	printf("%d\n", diff);

	return 0;
}
