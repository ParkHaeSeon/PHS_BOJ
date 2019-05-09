#include <iostream>
#include <deque>
#include <list>
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
#include <functional>
#include <unordered_map>  
#include <unordered_set>  
#include <tuple>
#include <sstream>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")

using namespace std;

int N = 0;

int sum[100100] = { 0, };

int main(void)
{
	int A = 0, s = 0, M = 0, start = 0, end = 0;

	bool first = true;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A);

		sum[i] += sum[i - 1] + A;	
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &start, &end);

		printf("%d\n", sum[end] - sum[start - 1]);
	}

	return 0;
}