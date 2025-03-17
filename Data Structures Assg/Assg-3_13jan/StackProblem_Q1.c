#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

int stack[size];
int top = -1;
int right = 0, left = 0;

void cpush(char value)
{
    if (top == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        if (value == '(' || value == '{' || value == '[')
        {
            left++;
        }
        if (value == ')' || value == '}' || value == ']')
        {
            right++;
        }

        stack[++top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int isEmpty()
{
    return top == -1;
}

// upto here we written the functions for basic operations to the stack data structure

int main()
{
    char expression[] = "(2 + 3) * (5 - 2)";
    int i = strlen(expression); // remember to include the string.h library

    for (int j = 0; j < i; j++)
    {
        cpush(expression[j]);
    }

    printf("Top element is %c\n", peek());
    if (right != left)
    {
        printf("not Balanced\n");
    }
    else
        printf("Balanced\n");

    printf("Stack empty: %s\n", isEmpty() ? "true" : "false");

    return 0;
}
