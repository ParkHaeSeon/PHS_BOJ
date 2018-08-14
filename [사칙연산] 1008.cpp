#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

int main(void)
{
	double A = 0, B = 0;

	scanf("%lf %lf", &A, &B);

	printf("%.9lf\n", double(A / B));

	return 0;
}