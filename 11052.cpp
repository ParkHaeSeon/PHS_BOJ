#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N = 0; // ºØ¾î»§ÀÇ °³¼ö
int price[1001] = { 0, };
int ans[1001] = { 0, };

int main(void)
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &price[i]);
	}

	for (int j = 1; j <= N; j++)
	{
		for (int k = 1; k <= j; k++)
		{
			ans[j] = max(ans[j], price[k]+ans[j-k]);
		}
	}
	
	printf("%d\n", ans[N]);


	return 0;
}