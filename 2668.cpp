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

vector<int> v[101];
vector<int> ans;

int N = 0, start = 0;

bool stop = false;
bool visit[101] = { false, };

void DFS(int s)
{
	// Cycle�� ã������(stop�� true�� ��), �׳� �ٷ� return.
	if (stop) return;

	visit[s] = true;

	for (auto i : v[s])
	{
		if (start == i)
		{
			/*
			�ᱹ ans vector�� push_back �Ǵ� ����
			Cycle �Ǵ� ��� �������̴�.

			��) 
			1 �� 3 �� 1 �� ��, 1 ����
			3 �� 1 �� 3 �� ��, 3 ����
			4 �� 5 �� 5 �� ��, ���� �� �Ѵ�.(start�� 4�̰�, i�� 5�̱� �����̴�.)
			5 �� 5 �� ��, ����(start == 5 == i)
			*/

			ans.push_back(i);
			stop = true;
			return;
		}

		if(!visit[i]) DFS(i);
	}
}

int main(void)
{
	int n = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &n);
		v[i].push_back(n);
	}

	for (int i = 1; i <= N; i++)
	{
		start = i;
		stop = false;

		/*
		���⿡�� visit�� false�� �ʱ�ȭ ������Ѵ�.
		��� ������ ���Ͽ� Cycle�� �˻��ؾ� �ϱ� �����̴�.
		*/

		memset(visit, false, sizeof(visit));

		DFS(i);	
	}

	sort(ans.begin(), ans.end());

	printf("%d\n", ans.size());

	for (auto i : ans)
	{
		printf("%d\n", i);
	}

	return 0;
}