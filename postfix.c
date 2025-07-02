#include <stdio.h>
#include <stdlib.h>
#define MAX 20

char stk[20];
int top = -1;

int isEmpty()  
{  
    return top == -1;  
}

int isFull()  
{  
    return top == MAX - 1;  
}

char peek()  
{  
    return stk[top];  
}

char pop()  
{  
    if (isEmpty())  
        return -1;  

    char ch = stk[top];  
    top--;  
    return(ch);  
}

void push(char oper)  
{  
    if (isFull())  
        printf("Stack Full!!!!");  
    else {  
        top++;  
        stk[top] = oper;  
    }  
}

int checkIfOperand(char ch)   
{   
    return (!(ch == '+' || ch == '-' || ch == '*' || ch == '/')) ;   
}   

int precedence(char ch)   
{   
    switch (ch)   
    {   
    case '+':   
    case '-':   
        return 1;   
  
    case '*':   
    case '/':   
        return 2;   
  
    case '^':   
        return 3;   
    }   
    return -1;   
}

void convertInfixToPostfix(char* expression)   
{   
    int i, j = 0;
    char postfix[MAX];

    for (i = 0; expression[i]; ++i)   
    {   
        if (checkIfOperand(expression[i]))   
            postfix[j++] = expression[i];   
  
        else if (expression[i] == '(')   
            push(expression[i]);   
  
        else if (expression[i] == ')')   
        {   
            while (!isEmpty() && peek() != '(')   
                postfix[j++] = pop();   
            if (!isEmpty() && peek() != '(')   
                return; 
            else  
                pop();   
        }  
        else   
        {   
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))   
                postfix[j++] = pop();   
            push(   expression[i]);   
        }   
    }   
  
    while (!isEmpty())   
        postfix[j++] = pop();   
  
    postfix[j] = '\0';   
    printf("Postfix Expression: %s\n", postfix);   
}

int main()  
{  
    char expression[] = "2*5+7";   
    convertInfixToPostfix(expression);   
    return 0;   
}