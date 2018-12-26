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

int start = 100, goal = 0;

vector<int> error;

bool Chk(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < error.size(); j++)
		{
			if (s.at(i) - '0' == error.at(j))
			{
				return false;
			}
		}
	}

	return true;
}

int main(void)
{
	int M = 0, num = 0, result = 87654321;

	scanf("%d", &goal);

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num);

		error.push_back(num);
	}

	if (start == goal)
	{
		printf("0\n");
		return 0;
	}

	if (abs(start - goal) > 2)
	{
		int left = goal;
		int right = goal;
		
		while(1)
		{
			if (left < 0) left = 0;

			if (Chk(to_string(left)))
			{
				result = to_string(left).length();
				result += abs(goal - left);
				break;
			}

			if (Chk(to_string(right)))
			{
				result = to_string(right).length();
				result += abs(goal - right);
				break;
			}

			--left;
			++right;

			if (left == start)
			{
				result = abs(left - goal);	
				break;
			}
			else if (right == start)
			{
				result = abs(right - goal);
				break;
			}
		}

		printf("%d\n", result);
	}
	else if (abs(start - goal) == 1)
	{
		printf("1\n");
	}
	else if (abs(start - goal) == 2)
	{
		printf("2\n");
	}

	return 0;
}