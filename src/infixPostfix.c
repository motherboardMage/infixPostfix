#include <stdio.h>
#include "../include/infixPostfix.h"

token value;
extern symbol* topSym;
extern number* topNum;
char numStr[11];

void calculate(char operator)
{
    float a, b;
    a = topNum->data;
    pop('N');
    b = topNum->data;
    pop('N');

    switch (operator)
    {
    case '+':
        value.num = a + b;
        push(value, 'N');
        break;
    case '-':
        value.num = a - b;
        push(value, 'N');
        break;
    case '*':
        value.num = a * b;
        push(value, 'N');
        break;
    case '/':
        value.num = a / b;
        push(value, 'N');
        break;
    default:
        printf("Error! Invalid operator encountered\n");
        break;
    }
}

void evaluatePostfix(char expression[])
{
    while (getchar() != '\n' && getchar() != EOF);
    char *current = expression;
    while(*current != '\0')
    {
        if(*current == OPERATORS)
        {
            if(topNum == NULL || topNum->prev == NULL)
            {
                perror("Error! Invalid expresison\n");
                return;
            }
            else {calculate(*current);}
        }
        else
        {
            int iter = 0;
            while(*current != ' ' || *current != OPERATORS)
                {
                    numStr[iter] = *current;
                    iter++;
                    current++;
                }
            numStr[iter] = '\0';
            iter = 0;
            current--;
            sscanf(numStr, "%f", &value.num);
            push(value, 'N');
        }
        current++;
    }
}

void infixToPostfix(char* expression)
{
    return;
}