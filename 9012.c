#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct stack
{
	char p;
	struct stack *next;
}stack;

int T = 0; // 테스트 케이스 개수
char PS[51];
stack *top = NULL;

void push(char s)
{
	stack *temp = (stack*)malloc(sizeof(stack));

	if (top == NULL)
	{
		temp->p = s;
		temp->next = NULL;
		top = temp;
	}
	else
	{
		temp->p = s;
		temp->next = top;
		top = temp;
	}
}

int pop()
{
	if (top == NULL)
	{
		return -2;
	}

	top = top->next;

	return 1;
}

int search()
{
	int i = 0;
	char r;

	while (PS[i] != '\0')
	{
		if (PS[i] == '(')
		{
			push(PS[i]);
		}
		else
		{
			if(pop() == -2) return -1;
		}

		++i;
	}

	if (top != NULL) return -1;
	else return 0;
}

int main(void)
{
	char input;

	scanf("%d", &T);

	while (T > 0)
	{
		memset(PS, '\0', sizeof(PS));

		top = NULL;

		scanf("%s", PS);

		if( search() == -1) printf("NO\n");
		else printf("YES\n");

		--T;
	}
	
	return 0;
}