#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int memo[1001] = { 0, };
int T = 0;

int fibo(int n)
{
	if (n <= 1) return n;
	else if (n == 2) return 2;
	else if (n == 3) return 4;
	
	if (memo[n] != 0) return memo[n];
	
	memo[n] = fibo(n - 1) + fibo(n - 2) +fibo(n-3);

	return memo[n];
}

int main(void)
{
	int n = 0;
	
	scanf("%d", &T);

	while (T > 0)
	{
		scanf("%d", &n);

		printf("%d\n", fibo(n));

		--T;
	}

	return 0;
}