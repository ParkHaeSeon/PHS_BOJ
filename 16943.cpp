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
#include <set>
#include <sstream>
#include <tuple>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")

using namespace std;

string A, B;

vector<char> v;

int MAX = -1, b = 0;

bool use[12] = { false, };

void simulation(string s)
{
	if (s.length() == A.length())
	{
		if (s.at(0) == '0') return;

		int a = atoi(s.c_str());

		if (a <= b) MAX = max(MAX, a);

		return;
	}

	for (int i = 0; i < v.size(); i++)
		if (!use[i])
		{
			s += v.at(i);
			use[i] = true;
			
			simulation(s);

			s = s.substr(0, s.length() - 1);
			use[i] = false;
		}
}

int main(void)
{
	MAX = -1;

	cin >> A >> B;

	for (int i = 0; i < A.length(); i++) v.push_back(A.at(i));
	
	b = atoi(B.c_str());

	simulation("");

	printf("%d\n", MAX);

	return 0;
}