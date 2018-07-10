#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

stack<char> L;
stack<char> R;

char s[600001];

int N = 0; // 입력할 명령어의 개수

int main(void)
{
	int i = 0;
	char input, data;


	scanf("%s", s); // 문자열 입력

	while (s[i] != '\0')
	{
		L.push(s[i]);

		++i;
	}
	
	scanf("%d", &N); // 입력할 명령어의 개수

	getchar();
	
	while (N > 0)
	{
		scanf("%c", &input);

		if (input == 'L')
		{
			if (!L.empty())
			{
				R.push(L.top());

				L.pop();
			}
		}
		else if (input == 'D')
		{
			if (!R.empty())
			{
				L.push(R.top());

				R.pop();
			}
		}
		else if (input == 'B')
		{
			if(!L.empty()) L.pop();
		}
		else if (input == 'P')
		{
			getchar();

			scanf("%c", &data);

			L.push(data);
		}

		getchar();

		--N;
	}

	while (!L.empty())
	{
		R.push(L.top());

		L.pop();
	}

	while (!R.empty())
	{
		printf("%c", R.top());

		R.pop();
	}

	printf("\n");

	return 0;
}