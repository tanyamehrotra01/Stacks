/*Postfix expression evaluation in stacks
1. Scan the expression from left to right
2. If it is an operand, push
3. If it is an operator, pop two elements from the stack
4. Perform the operation on the popped elements and push the result back into the stack
5. Repeat steps 3 and 4 till all elements are scanned
6. Only one element remains in the stack which is the value of the expression*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

char stack[SIZE];
int top = -1;

void push(char data)
{
	if(top == SIZE)
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
		return -1;
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
	char exp[SIZE];
    char *e;
    printf("Enter the expression : ");
    scanf("%s",exp);
    e = exp;
    while (*e != '\0')
    {
    	if(isdigit(*e))
    		{
    			int num = *e - 48;
    			push(num);
    		}
    	else
    	{	
    		int result = 0;
    		int op2 = pop();
    		int op1 = pop();
    		switch(*e)
    		{ 
    			case '+':
    			result = op1 + op2;
    			break;
    			case '-':
    			result = op1 - op2;
    			break;
    			case '*':
    			result = op1 * op2;
    			break;
    			case '/':
    			result = op1 / op2;
    			break;
    			case '%':
    			result = op1 % op2; 
    			break;
    		}
    	push (result);
    	}
    	e++;
    }
    printf("Value of expression is = %d ", pop());
}

