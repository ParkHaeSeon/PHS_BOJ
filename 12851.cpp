// 다시 문제를 풀어보았다. 12581번 숨바꼭질 2
// 1697번 문제 코드 활용

/*
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 
동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고, 
가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램을 작성하시오.
입력 : 5 17
출력 : 4 2
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N = 0; // 수빈이 위치
int K = 0; // 동생의 위치
int fastCnt = 0; // 가장 빠른 시간으로 찾는 방법의 수
int fastTime = 123456789; // 가장 빠른 시간

queue<pair<int, int> > q; // 위치 저장 및 시간(초) 저장

int visit[100001] = { 0, };

int find(int start, int end)
{
	int pos = 0, cnt = 0;

	visit[start] = 1;

	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++)
		{
			pos = q.front().first;
			cnt = q.front().second;

			q.pop();

			visit[pos] = 1;

			if (pos == K) // 수빈의 위치에서 동생의 위치까지 도달했을 때
			{
				fastTime = min(cnt, fastTime);; 
				// 최신으로 꺼내온 동생의 위치까지 도달한 시간(cnt)과 
				// 그 전에 저장한 동생의 위치까지 도달한 가장 빠른 시간(fastTime)을 비교

				if (cnt == fastTime) ++fastCnt;
				// 가장 빠르게 도달한 시간(fastTime)과 최신으로 꺼내온 수빈의 위치에서 동생의 위치까지 도달했을 때의 시간(cnt)이
				// 같다면 fastCnt 1 증가.(가장 빠른 시간의 경우이므로)
			}

			if (pos - 1 >= 0 && visit[pos - 1] == 0)
			{
				q.push(make_pair(pos - 1, cnt + 1));

				//visit[pos - 1] = 1;
			}

			if (pos + 1 <= 100000 && visit[pos + 1] == 0)
			{
				q.push(make_pair(pos + 1, cnt + 1));

				//visit[pos + 1] = 1;
			}

			if (2 * pos <= 100000 && visit[2 * pos] == 0)
			{
				q.push(make_pair(2 * pos, cnt + 1));

				//visit[2 * pos] = 1;
			}
		}
	}

	return fastTime;
}

int main(void)
{
	scanf("%d %d", &N, &K);

	printf("%d\n", find(N, K));

	printf("%d\n", fastCnt);

	return 0;
}


/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

int Cnt = 0;
int MIN_DATA = 7654321;

queue<pair<int, int>> q;

int v[100001] = { 0, };

int find(int N, int K)
{
	q.push(make_pair(N, 0));
	v[N] = 1;

	int qData = 0, qCnt = 0, qSzie = 0;

	while (!q.empty())
	{
		qData = q.front().first;
		qCnt = q.front().second;

		q.pop();		

		if (qData == K)
		{
			MIN_DATA = min(MIN_DATA, qCnt);

			if(MIN_DATA == qCnt) Cnt++;
		}

		if (qData - 1 >= 0 && !v[qData - 1])
		{
			q.push(make_pair(qData - 1, qCnt + 1));
		}

		if (qData + 1 < 100001 && !v[qData + 1])
		{
			q.push(make_pair(qData + 1, qCnt + 1));
		}

		if (qData * 2 < 100001 && !v[qData * 2])
		{
			q.push(make_pair(qData * 2, qCnt+1));
		}

		v[qData] = 1;
	}

	return MIN_DATA;
}

int main(void)
{
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d\n", find(N, K));

	printf("%d\n", Cnt);
	
	return 0;
}
*/
