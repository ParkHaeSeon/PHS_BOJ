#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int L = 0, C = 0;

int mo = 0, ja = 0;

vector<char> alpha;

vector<char> v;

void DFS(int cnt, int mo, int ja)
{
	if (v.size() == L)
	{
		if (mo >= 1 && ja >= 2)
		{
			for (auto i : v)
			{
				printf("%c", i);
			}

			printf("\n");
		}

		return;
	}

	for (int i = cnt; i < C; i++)
	{
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
		{
			v.push_back(alpha[i]);
			DFS(i + 1, mo+1, ja);
			v.pop_back();
		}
		else
		{
			v.push_back(alpha[i]);
			DFS(i + 1, mo, ja+1);
			v.pop_back();
		}
	}
}

int main(void)
{
	scanf("%d %d", &L, &C);

	alpha.resize(C);

	for (int i = 0; i < C; i++)
	{
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	DFS(0, 0, 0);

	return 0;
}