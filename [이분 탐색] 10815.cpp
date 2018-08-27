#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> v;

vector<int> ans;

int N = 0;

int searchNumber(int left, int right, int search)
{
	if (left > right) return 0;

	int middle = (left + right) / 2;

	if (v[middle] == search)	return 1;
	else if (v[middle] < search) searchNumber(middle + 1, right, search);
	else searchNumber(left, middle - 1, search);
}

int main(void)
{
	int input_num = 0, search_cnt = 0, search_num = 0;

	scanf("%d", &N);
	
	while (N--)
	{
		scanf("%d", &input_num);

		v.push_back(input_num);
	}

	sort(v.begin(), v.end()); // 이분 탐색은 반드시 정렬된 상태여야 한다.

	scanf("%d", &search_cnt);

	while (search_cnt--)
	{
		scanf("%d", &search_num);

		ans.push_back(searchNumber(0, v.size() - 1, search_num));
	}

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}

	return 0;
}