#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define max 100

char stack[max];
int top = -1;

void push(char c)
{
    if (top == max - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = c;
    }
}

char pop()
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

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

void infixTopostfix(char *infix, char *postfix)
{
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j++] = '\0';
}

int main()
{
    char infix[max], postfix[max];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixTopostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    return 0;
}