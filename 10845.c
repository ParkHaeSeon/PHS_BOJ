#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Queue
{
	int data;
	struct Queue *next;
}Queue;

Queue *front = NULL;
Queue *back = NULL;

int N = 0;

void Push(int get_Data)
{
	Queue *temp = (Queue*)malloc(sizeof(Queue));

	if (front == NULL && back == NULL)
	{
		temp->data = get_Data;
		temp->next = NULL;
		front = temp;
		back = temp;
	}
	else
	{
		temp->data = get_Data;
		temp->next = back;
		back = temp;
	}
}

int Pop()
{
	if (front == NULL && back == NULL) return -1;

	int send_Data = 0;

	Queue *pre = NULL;

	send_Data = front->data;

	if (front == back)
	{
		front = NULL;
		back = NULL;

		return send_Data;
	}

	pre = back;

	while (pre->next != front)
	{
		pre = pre->next;
	}

	pre->next = NULL;

	front = pre;

	return send_Data;
}

int Size()
{
	if (front == NULL && back == NULL) return 0;
	else
	{
		int count = 0;

		Queue *Cnt = NULL;

		Cnt = back;

		while (Cnt)
		{
			Cnt = Cnt->next;

			++count;
		}

		return count;
	}
}

int Empty()
{
	if (front == NULL && back == NULL) return 1;
	else return 0;
}

int Front()
{
	if (front == NULL && back == NULL) return -1;
	else return front->data;
}

int Back()
{
	if (front == NULL && back == NULL) return -1;
	else return back->data;
}

int main(void)
{
	char input[10];
	int input_number = 0;

	scanf("%d", &N);

	while (N > 0)
	{
		scanf("%s", input);

		if (strcmp(input, "push") == 0)
		{
			scanf("%d", &input_number);

			Push(input_number);
		}
		else if (strcmp(input, "pop") == 0)
		{
			printf("%d\n", Pop());
		}
		else if (strcmp(input, "size") == 0)
		{
			printf("%d\n", Size());
		}
		else if (strcmp(input, "empty") == 0)
		{
			printf("%d\n", Empty());
		}
		else if (strcmp(input, "front") == 0)
		{
			printf("%d\n", Front());
		}
		else if (strcmp(input, "back") == 0)
		{
			printf("%d\n", Back());
		}

		--N;
	}

	return 0;
}