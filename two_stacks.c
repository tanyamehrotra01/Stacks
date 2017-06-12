/*Implement two stacks using one array
1. Start two indices, one on left and the other on right of the array
2. Left end stimulates first stack and right end stimulates second stack
3. To push an element into first stack, put it at the left index
4. To push an element into second stack, put it into right index
5. First stack gets grown towards right, second stack grows towards left*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

int stack1[SIZE/2];
int stack2[SIZE/2];
int top1 = -1;
int top2 = SIZE-1;

int arr[SIZE];

void push_stack1(int data)
{
	if(top1 == SIZE/2)
	{
		printf("Overflow\n");
	}
	else
	{
		stack1[++top1] = data;
	}
}

int pop_stack1()
{
	int value;
	if( top1 == -1)
	{
		printf("Underflow\n");
		return -1;
	}
	
	else
	{
		value = stack1[top1];
		top1--;
	}
	return value;
}

void push_stack2(int data)
{
	if(top2 == SIZE/2-1)
	{
		printf("Overflow\n");
	}
	else
	{
		stack2[--top2] = data;
	}
}

int pop_stack2()
{
	int value;
	if( top2 == SIZE-1)
	{
		printf("Underflow\n");
		return -1;
	}
	
	else
	{
		value = stack2[top2];
		top2++;
	}
	return value;
}

int main()
{
	printf("Input the first stack");
	int i;
	for (i = 0; i < SIZE/2-1 ; i++)
	{
		scanf("%d\n",&stack1[i]);
		push_stack1(stack1[i]);
	}
	printf("Input the second stack");
	
	for (i = 0; i < SIZE/2 ; i++)
	{
		scanf("%d\n",&stack2[i]);
		push_stack2(stack2[i]);
	}
	
	int x = 0, y = SIZE-1;
	while( !(x>y))
	{
		arr[x] = pop_stack1();
		x++;
		arr[y] = pop_stack2();
		y--;
	}

	printf("Array is : ");
	int j;
	for (j = 0; j < SIZE ; j++)
	{
		printf("%d\t",arr[j]);
	}

}