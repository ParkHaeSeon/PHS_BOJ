#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct stack
{
	int data;
	struct stack *next;
}stack;

stack *top_stack = NULL; // �׻� ���� ����Ŵ. 

void push(int n)
{
	stack *temp = (stack*)malloc(sizeof(stack));

	if (top_stack == NULL) // �� ó�� ����(�����ϴ� ��尡 ���ٸ�)
	{
		temp->data = n;
		temp->next = NULL;
		top_stack = temp;
	}
	else // �̹� �����ϴ� ��尡 1�� �̻��̶��
	{
		temp->data = n;
		temp->next = top_stack;
		top_stack = temp;
	}
}

int pop()
{
	if (top_stack == NULL) // ���ÿ� ����ִ� ������ ���� ��
	{
		return -1;
	}

	// ������ ����ִ� ���
	int a = 0;

	a = top_stack->data;

	top_stack = top_stack->next;

	return a;
}

int size()
{
	stack *pre = NULL;

	int i = 0;

	if (top_stack == NULL)
	{
		return 0;
	}

	pre = top_stack;

	while (pre)
	{
		pre = pre->next;

		++i;
	}

	return i;
}

int empty()
{
	if (top_stack == NULL)
	{
		return 1;
	}

	return 0;
}

int top()
{
	int b = 0;

	if (top_stack == NULL)
	{
		return -1;
	}

	b = top_stack->data;

	return b;
}

int main(void)
{
	int N = 0; // ����� ��
	char Input[10];
	int num = 0;

	scanf("%d", &N);

	while (N > 0)
	{
		scanf("%s", Input);

		if (strcmp(Input, "push") == 0)
		{
			scanf("%d", &num);

			push(num);
		}
		else if (strcmp(Input, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(Input, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(Input, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if (strcmp(Input, "top") == 0)
		{
			printf("%d\n", top());
		}
		//else if (strcmp(Input, "exit") == 0)
		//{
		//	break;
		//}

		--N;
	}

	return 0;
}