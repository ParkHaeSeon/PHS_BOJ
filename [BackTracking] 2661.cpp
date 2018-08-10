#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N = 0;

bool stop = false;

bool same_chk(string s)
{
	int len = s.length() / 2;

	int L = s.length();

	for (int i = 1; i <= len; i++)
	{
		string Front = s;
		string Back = s;

		int Back_start = L - i;
		int Front_start = Back_start - i;

		Front = Front.substr(Front_start, i);
		Back = Back.substr(Back_start, i);

		if (Front == Back) return true;
	}

	return false;
}

void DFS(string ans, int pos, int before)
{
	if (stop) return;

	if (pos == N)
	{
		cout << ans;

		stop = true;

		printf("\n");

		return;
	}

	for (int i = 1; i <= 3; i++)
	{
		char temp = i + '0';

		if (i != before && !same_chk(ans + temp))
		{
			DFS(ans + temp, pos + 1, i);
		}

		/*
		// Error Code !!!

		ans  += i + '0'; // not string + int

		if (i != before && !same_chk(ans))
		{
			DFS(ans, pos + 1, i);
		}
		*/
	}
}

int main(void)
{
	scanf("%d", &N);

	DFS("", 0, -1);

	return 0;
}