/*
Below are the steps to implement the above idea:

Scan the infix expressionressionression from left to right.
    If the scanned character is an operand, put it in the postfix expressionressionression.
Otherwise, do the following
    If the precedence of the current scanned operator is higher than the precedence of the operator on top of the stack, or if the stack is empty, or if the stack contains a ‘(‘, then push the current operator onto the stack.
Else, pop all operators from the stack that have precedence higher than or equal to that of the current operator. After that push the current operator onto the stack.
    If the scanned character is a ‘(‘, push it to the stack.
    If the scanned character is a ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis.
Repeat steps 2-5 until the infix expressionressionression is scanned.

Once the scanning is over, Pop the stack and add the operators in the postfix expressionressionression until it is not empty.
Finally, print the postfix expressionressionression.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(const char *expression) {
    int len = strlen(expression);
    char result[MAX];
    char stack[MAX];
    int j = 0;
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = expression[i];

        if (isspace(c)) {
            continue; 
        }

        if (isalnum(c)) {
            result[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }
            top--; 
        } else {
            while (top != -1 && prec(c) <= prec(stack[top])) {
                result[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        result[j++] = stack[top--];
    }

    result[j] = '\0';
    printf("%s\n", result);
}

int main() {
    char expression[] = "(2 + 3) *5";
    printf("\n\n\n\nThe original expression(Infix) was : %s\n",expression);
    printf("The Converted expression(Postfix) was : ");
    infixToPostfix(expression);
    printf("\n\n\n\n\n");
    return 0;
}
