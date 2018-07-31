#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int height[9] = { 0, };

vector<int> ans;

int main(void)
{
	int h = 0, sum = 0, idx1 = 0, idx2 = 0;
	bool Complete = false;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &height[i]);

		sum += height[i];
	}

	for (int i = 0; i < 9 && !Complete; i++)
	{
		for (int j = 0; j < 9 && !Complete; j++)
		{
			if ( (i != j) && ((sum - height[i] - height[j]) == 100) )
			{
				idx1 = i;
				idx2 = j;
				Complete = true;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if(i != idx1 && i != idx2) ans.push_back(height[i]);
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", ans[i]);
	}

	return 0;
}