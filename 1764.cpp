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

int N = 0, M = 0;

vector<string> v, ans;

bool bs(int left, int right, string s)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (v.at(middle) == s)
		{
			cout << "Å×½ºÆ® = " << s << '\n';
			return true;
		}
		else if (v.at(middle) < s) left = middle + 1;
		else if (v.at(middle) > s) right = middle - 1;
	}

	return false;
}

int main(void)
{
	int cnt = 0;

	string s;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		cin >> s;

		v.push_back(s);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++)
	{
		cin >> s;

		if (bs(0, v.size() - 1, s))
		{
			ans.push_back(s);
		}
	}

	printf("%d\n", ans.size());

	for (auto i : ans) cout << i << '\n';

	return 0;
}