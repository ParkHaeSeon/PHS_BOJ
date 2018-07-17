#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N = 0; // 수열의 크기

vector<int> v; // LIS

int main(void)
{
	int num = 0;

	scanf("%d", &N); // 수열의 크기 입력

	scanf("%d", &num);

	v.push_back(num);

	for (int i = 1; i < N; i++)
	{
		scanf("%d", &num);

		if (v.back() < num)
		{
			v.push_back(num);
		}
		else
		{
			auto it = lower_bound(v.begin(), v.end(), num);

			*it = num;
		}
	}

	cout << v.size() << endl;

	return 0;
}