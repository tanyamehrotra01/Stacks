/*Evaluate an infix expression in one scan in a stack 
1. Create an empty operator and operand stack, initializing operator stack with the least precedence #
2. Scan the expression from left to right
3. If token is an operand, push in operand stack
4. If token is an operator. do the following: 
   a) Pop operator from operand stack
   b) Check its precedence with the token
   c) If its precedence is higher, push popped operator and then the token
   d) Else if its precedence is lower, pop two operands and perform operation
   e) Push result into operand stack
   f) Repeat above steps untill token becomes less than popped operator
5. After string ends, start popping operator from operator stack and two operands from operand stack
6. Repeat step (d) untill dummy operator # is found
7. Pop value from operand stack and print it*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

char operator[SIZE];
char operand[SIZE];
int top1 = -1;
int top2 = -1;

void push_operand(int data)
{
	if(top1 == SIZE-1)
	{
		printf("Overflow\n");
	}
	else
	{
		operand[++top1] = data;
	}
}

char pop_operand()
{
	int value;
	if( top1 == -1)
	{
		printf("Underflow\n");
		return -1;
	}
	
	else
	{
		value = operand[top1];
		top1--;
	}
	return value;
}

void push_operator(char data)
{
	if(top2 == SIZE-1)
	{
		printf("Overflow\n");
	}
	else
	{
		operator[++top2] = data;
	}
}

char pop_operator()
{
	char value;
	if( top2 == -1)
	{
		printf("Underflow\n");
		return -1;
	}
	
	else
	{
		value = operator[top2];
		top2--;
	}
	return value;
}

int precedence(char ch)
{
	switch(ch)
	{
		case '#':return 0;
		case '+':return 1;
		case '-':return 1;
		case '*':return 2;
		case '/':return 2;
		case '(':return 3;
		default :printf("Invalid operator");

	}
}

double evaluate(char ch, int op1, int op2)
{
	switch(ch)
	{
		case '+': return op1+op2;
		case '-': return op1-op2;
		case '*': return op1*op2;
		case '/': return op1/op2;
		default:
		return 0;
	}
}

int is_operator(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		return 1;
		default : return 0;
	}
}

int main()
{
	char exp[SIZE];
    char *e;
    printf("Enter the expression : ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
    	push_operator('#');
    	if( isdigit(*e))
    	{
    		int num = *e - 48;
    		push_operand(num);
    	}
    	
    	else if(is_operator(*e))
    	{
    		char popped_operator = pop_operator();
    		int result = 0;
    		if(precedence(popped_operator) < precedence(*e))
    			{
    				push_operator(popped_operator);
    				push_operator(*e);
    			}

    	
    		else
    		{
    			while(precedence(*e) <= precedence(popped_operator))
    			{
    				int op2 = pop_operand();
    				int op1 = pop_operand();
    				result = evaluate(popped_operator, op1,op2);
       				push_operand(result);
       				popped_operator = pop_operator();
       			}
       			push_operator(popped_operator);
       			push_operator(*e);
       		}
    	}
    	
    	e++;
    }
    char popped_operator = pop_operator();
    while(popped_operator != '#')
    {
    	int result = 0;
    	int op2 = pop_operand();
    	int op1 = pop_operand();
    	int res = evaluate( popped_operator, op1,op2);
		push_operand(res);
    }
    printf("Value of infix expression is : %d", pop_operand());
}