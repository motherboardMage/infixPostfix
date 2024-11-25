#include <stdio.h>
#include <stdlib.h>
#include "../include/infixPostfix.h"

extern symbol* topSym;
extern number* topNum;

void push(token value, char type)
{
    if(type == 'S')
    {
        symbol* tempSym = (symbol*)calloc(1, sizeof(symbol));
        tempSym->data = value.sym;
        tempSym->prev = NULL;

        if(topSym == NULL)
        {
            topSym = tempSym;
        }
        else
        {
            tempSym->prev = topSym;
            topSym = tempSym;
        }
    }
    else if(type == 'N')
    {
        number* tempNum = (number*)calloc(1, sizeof(number));
        tempNum->data = value.num;
        tempNum->prev = NULL;

        if(topNum == NULL)
        {
            topNum = tempNum;
        }
        else
        {
            tempNum->prev = topNum;
            topNum = tempNum;
        }
    }
    else
    {
        printf("Error! Invalid token type\n");
    }
}

void pop(char type)
{
    switch (type)
    {
    case 'S':
        if(topSym->prev == NULL)
        {
            free(topSym);
            topSym = NULL;
        }
        else if(topSym == NULL)
        {
            printf("Error! Stack is empty\n");
        }
        else
        {
            symbol* tempPtr = topSym;
            topSym = topSym->prev;
            free(tempPtr);
        }
        break;
        
    case 'N':
        if(topNum->prev == NULL)
        {
            free(topNum);
            topNum = NULL;
        }
        else if(topNum == NULL)
        {
            printf("Error! Stack is empty\n");
        }
        else
        {
            number* tempPtr = topNum;
            topNum = topNum->prev;
            free(tempPtr);
        }
        break;
        
    default:
        perror("Error! Invalid stack type\n");
        break;
    }
}