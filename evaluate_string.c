#include <stdio.h>
#include <stdbool.h>

int length(char* s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

bool is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infix_to_postfix(char* s, char* postfix) {
    char stack[100];
    int top = -1;
    int i = 0, k = 0;
    int len = length(s);

    while (i < len) {
        if (s[i] == ' ') {
            i++;
            continue;
        }

        if (s[i] >= '0' && s[i] <= '9')
        {
            while (i < len && (s[i] >= '0' && s[i] <= '9')) 
            {
                postfix[k++] = s[i++];
            }

            postfix[k++] = ' ';  
        } 
        else if (is_operator(s[i])) 
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(s[i])) 
            {
                postfix[k++] = stack[top--];
                postfix[k++] = ' ';
            }
            stack[++top] = s[i++];
        } 
        else 
        {
            i++;
        }
    }

    while (top >= 0) 
    {
        postfix[k++] = stack[top--];
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';  
}

int eval_postfix(char* postfix) {
    int stack[100];
    int top = -1;
    int i = 0, len = length(postfix);

    while (i < len) {
        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        if (postfix[i] >= '0' && postfix[i] <= '9') {
            int num = 0;
            while (i < len && (postfix[i] >= '0' && postfix[i] <= '9'))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            stack[++top] = num;
        } 
        
        else if (is_operator(postfix[i])) {
            int b = stack[top--];
            int a = stack[top--];
            int result;

            switch (postfix[i]) {
                case '+': result = a + b; 
                          break;
                case '-': result = a - b; 
                          break;
                case '*': result = a * b; 
                          break;
                case '/': result = a / b; 
                          break;
            }

            stack[++top] = result;
            i++;
        } else {
            i++;
        }
    }

    return stack[top];
}


int calculate(char* s) {
    char postfix[100];

    infix_to_postfix(s, postfix);

    return eval_postfix(postfix);
}

void main()
{
    printf("%d\n", calculate("3*4+3"));
}