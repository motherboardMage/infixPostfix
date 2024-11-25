#ifndef INFIXPOSTFIX_H
#define INFIXPOSTFIX_H
#define PARANTHESIS '(' || ')' || '{' || '}' || '[' || ']'
#define OPERATORS '+' || '-' || '/' || '*'

typedef union token
{
    char sym;
    float num;
}token;

typedef struct symbol
{
    char data;
    struct symbol* prev;
}symbol;

typedef struct number
{
    float data;
    struct number* prev;
}number;

void mainMenu();
void push(token value, char type);
void pop(char type);
void evaluatePostfix(char* expression);
void infixToPostfix(char* expression);
int precedence(char ch);
void calculate(char operator);

#endif
