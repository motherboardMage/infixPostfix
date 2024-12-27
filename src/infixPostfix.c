#include <stdio.h>
#include <stdlib.h>
#include "../include/infixPostfix.h"

token value;
extern symbol* topSym;
extern number* topNum;

void calculate(char operator)
{
    // Pop the top two values in the stack and operate on them
    float a, b;
    a = topNum->data;
    pop('N');
    b = topNum->data;
    pop('N');

    switch (operator)
    {
    case '+':
        value.num = a + b;
        break;
    case '-':
        value.num = a - b;
        break;
    case '*':
        value.num = a * b;
        break;
    case '/':
        value.num = a / b;
        break;
    default:
        printf("Error! Invalid operator encountered\n");
        break;
    }
    push(value, 'N');   // Push value to number stack
}

void evaluatePostfix(char expression[])
{
    while (getchar() != '\n');
    char* current = expression;
    char* numStr = (char*)calloc(11, sizeof(char));

    // Scan the expression string until EOL is reached
    while(*current != '\0')
    {
        if(isOperator(current))
        {
            /*
            It does not make sense to encounter an
            operator if the number stack is empty
            */
            if(topNum == NULL || topNum->prev == NULL)
            {
                perror("Error! Invalid expresison\n");
                return;
            }
            else {calculate(*current);}
        }

        else if(*current == ' ') current++;

        else
        {
            int iter = 0;

            // Start reading the number
            while(*current != ' ' || !isOperator(current))
                {
                    numStr[iter] = *current;
                    printf("Value read: %d\n", *current);
                    iter++;
                    current++;
                    /*
                    This basically created a string of
                    the multi-digit number (if it is one)
                    */
                }
            numStr[iter] = '\0';
            iter = 0;
            sscanf(numStr, "%f", &value.num); // Convert the string into a float
            printf("Number read: %f\n", value.num);
            push(value, 'N');
        }
        current++;
    }
}

void infixToPostfix(char* expression)
{
    // TODO
    return;
}

int isOperator(char* value)
{
    switch (*value)
    {
    case '+':
        goto yes;
        break;
    case '-':
        goto yes;
        break;
    case '*':
        goto yes;
        break;
    case '/':
        goto yes;
        break;
    case '^':
        goto yes;
        break;

    default:
        goto no;
        break;
    }

yes:
    return 1;
no:
    return 0;
}
