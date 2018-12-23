#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<char> v;

int main(void)
{
	int N = 0, MAX = -1, T = 0;
	char c;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
		{
			cin >> c;

			if (MAX <= (int)c)
			{
				MAX = (int)c;

				v.insert(v.begin(), c);
			}
			else v.push_back(c);		
		}

		printf("#%d ", tc);

		for (auto i : v) cout << i;

		printf("\n");

		v.clear();
		MAX = -1;
	}

	return 0;
}