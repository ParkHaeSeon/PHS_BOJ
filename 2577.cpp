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

int main(void)
{
	int A = 0, B = 0, C = 0;

	int num[10] = { 0, };

	scanf("%d %d %d", &A, &B, &C);

	string s = to_string(A*B*C);

	for (int i = 0; i < s.length(); i++)
		++num[s.at(i) - '0'];

	for (int i = 0; i <= 9; i++) 
		printf("%d\n", num[i]);
	
	return 0;
}