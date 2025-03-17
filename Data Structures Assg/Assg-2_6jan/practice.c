
/*
The Problem: Implementing a Stack-Based Expression Evaluator 
You are tasked with creating a Mathematical Expression Evaluator for a 
simple calculator application. The application should: 
1.  Validate the Expression (Parenthesis Matching) 
a.  Ensure that the input expression has balanced parentheses before proceeding with evaluation. 
b.  Examples: i. Input: (2 + 3) * (5 - 2) → Output: Balanced        ii. Input: (2 + 3 * (5 - 2) → Output: Not Balanced 

2.  Infix to Postfix Conversion 
a.  Convert the input infix expression to postfix format using stack operations.
b.  Consider operator precedence and associativity rules. 
c.  Examples: i. Input: (2 + 3) * 5 → Output: 2 3 + 5 *         ii. Input: 10 + (6 * 2) → Output: 10 6 2 * + 
*/


//Q1
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX 100

// typedef struct Stack {
//     int top;
//     char items[MAX];
// } Stack;

// void push(Stack* s, char value) {
//     if (s->top == MAX - 1) {
//         printf("Stack Overflow\n");
//     } else {
//         s->items[++(s->top)] = value;
//     }
// }

// char pop(Stack* s) {
//     if (s->top == -1) {
//         printf("Stack Underflow\n");
//         return '\0'; // Return null character
//     } else {
//         return s->items[(s->top)--];
//     }
// }

// int isBalanced(const char* expression) {
//     Stack stack;
//     stack.top = -1;
    
//     for (int i = 0; i < strlen(expression); i++) {
//         char ch = expression[i];
//         if (ch == '(') {
//             push(&stack, ch);
//         } else if (ch == ')') {
//             if (stack.top == -1) {
//                 return 0; // Not balanced
//             } else {
//                 pop(&stack);
//             }
//         }
//     }
//     return stack.top == -1; // Balanced if stack is empty
// }

// int main() {
//     const char* expression1 = "(2 + 3) * (5 - 2)";
//     const char* expression2 = "(2 + 3 * (5 - 2)";
    
//     printf("Expression 1: %s -> %s\n", expression1, isBalanced(expression1) ? "Balanced" : "Not Balanced");
//     printf("Expression 2: %s -> %s\n", expression2, isBalanced(expression2) ? "Balanced" : "Not Balanced");

//     return 0;
// }

//Q2

#include <stdio.h>
#include <ctype.h>

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    stack.top = -1;
    int k = 0;
    
    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from stack
        } else if (isOperator(ch)) {
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }
    while (stack.top != -1) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';
}

int main() {
    const char* infix1 = "(2+3)*5";
    const char* infix2 = "10+(6*2)";
    char postfix1[MAX];
    char postfix2[MAX];
    
    infixToPostfix(infix1, postfix1);
    infixToPostfix(infix2, postfix2);
    
    printf("Infix: %s -> Postfix: %s\n", infix1, postfix1);
    printf("Infix: %s -> Postfix: %s\n", infix2, postfix2);
    
    return 0;
}
