/*Paranthesis Matching in Stacks
1. Input the expression in the form of a string
2. If you encounter an opening bracket, push
3. If you encounter a closing bracket, pop
4. If popped value and the closing bracket in the expression
   do not belong to the same set of brackets, then expression
   is not valid.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

char stack[SIZE];
int top = -1;

void push(char data)
{
	if(top == SIZE-1)
	{
		printf("Overflow\n");
	}
	else
	{
		stack[++top] = data;
	}
}

char pop()
{
	char value;
	if( top == -1)
	{
		printf("Underflow\n");
		return 0;
	}
	
	else
	{
		value = stack[top];
		top--;
	}
	return value;
}

int main()
{
	printf("Enter the Expression containing only brackets : ");
	char a[SIZE];
	gets(a);
	int l = strlen(a);
	int i;
	for( i = 0 ; i < l ; i++)
	{
		int popped_value;
		if(a[i] == '(' || a[i] == '{' || a[i] == '[')
			push(a[i]);
		
		else
		{
			if(a[i] == ')')
			{
				popped_value = pop();
				if(popped_value != '(')
				{
					printf("Expression is not valid\n");
					return 0;
				}
			}
			else if(a[i] == '}')
			{
				popped_value = pop();
				if(popped_value != '{')
				{
					printf("Expression is not valid\n");
					return 0;
				}
			}
			else if(a[i] == ']')
			{
				popped_value = pop();
				if(popped_value != '[')
				{
					printf("Expression is not valid\n");
					return 0;
				}
			}
			else
			{
				printf("Expression is not valid!\n");
				return 0;
			}
		}
	}
	printf("Expression is Valid\n");
}