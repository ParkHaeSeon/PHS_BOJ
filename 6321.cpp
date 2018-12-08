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

vector<string> v;

string s;

int main(void)
{
	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		cin >> s;

		v.push_back(s);
	}

	for (int i = 0; i < N; i++)
	{
		printf("String #%d\n", i + 1);
		
		for (int j = 0; j < v.at(i).length(); j++)
		{
			int ret = v.at(i).at(j);
			
			++ret;

			if (ret == 91) ret = 65;

			printf("%c", (char)ret);
		}

		if(i != N - 1) printf("\n\n");
		else printf("\n");
	}

	return 0;
}