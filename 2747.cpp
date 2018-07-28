#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

long long Memoization[46] = { 0, };


long long Fibo(int number)
{
	if (number <= 1) return number;
	else if (number == 2) return 1;

	if (Memoization[number] != -1) return Memoization[number];

	Memoization[number] = Fibo(number - 1) + Fibo(number - 2);

	return Memoization[number];
}


int main(void)
{
	int n = 0;

	scanf("%d", &n);

	memset(Memoization, -1, sizeof(Memoization));

	printf("%lld\n", Fibo(n));

	return 0;
}
