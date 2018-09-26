#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<long long> v;

int main(void)
{
	int N = 0;

	long long input = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &input);

		v.push_back(input);
	}

	sort(v.begin(), v.end());

	int new_cnt = 1, before_cnt = 1;

	long long new_number = v[0], before_number = v[0];

	for (int i = 0; i < N - 1; i++)
	{
		// ������ ��� while ���� ����.
		while (v[i] == v[i + 1])
		{
			++new_cnt; // �� ���� �� ���� �ִ°�
			new_number = v[i];
			++i;
		}

		if (before_cnt < new_cnt)
		{
			before_number = new_number;
			before_cnt = new_cnt;
		}

		new_cnt = 1;
	}

	printf("%lld\n", before_number);

	return 0;
}