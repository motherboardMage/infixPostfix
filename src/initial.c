#include <stdio.h>
#include "../include/infixPostfix.h"

symbol* topSym;
number* topNum;

int main()
{
    topSym = NULL;
    topNum = NULL;
    mainMenu();
    return 0;
}

void mainMenu()
{
    int choice;
    char expression[201];

    while (1)
    {
        printf("\nWhat do you want to do?\n");

        printf("1. Evaluate postfix expression\n"
               "2. Convert infix to postfix\n"
               "3. Exit the program\n-> ");

        scanf("%d", &choice);
        while (getchar() != '\n');

        // looks shit but I like switches
        switch (choice)
        {
        case 1:
            printf("Enter expression\n-> ");
            fgets(expression, sizeof(expression), stdin);
            evaluatePostfix(expression);
            
            if(topNum == NULL)
            {
                printf("Error! Stack empty or evaluation failed\n");
                continue;
            }
            printf("%s = %f", expression, topNum->data);
            break;

        case 2:
            printf("Enter expression\n-> ");
            fgets(expression, sizeof(expression), stdin);
            infixToPostfix(expression);
            break;

        case 3:
            // TODO
            return;

        default:
            printf("Invalid choice!");
            break;
        }
    }
    return;
}