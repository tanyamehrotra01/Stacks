/*Infix to Postfix conversion in Stacks
1. Initialize the priority of various operators in the expression
2. Input the expression in the form of a string
3. If you encounter an operand, print it
4. Else If you encounter opening bracket, push it
5. Else If you encounter a closing bracket, pop and print untill top of stack is opening bracket
6. Else, pop and print untill the priority of top of stack is less than priority of incoming element.
7. Print the remaining elements in the stack.
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
		return -1;
	}
	
	else
	{
		value = stack[top];
		top--;
	}
	return value;
}

int priority( char x)
{
	if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
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
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
} 