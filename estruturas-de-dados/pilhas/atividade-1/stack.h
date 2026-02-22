#include "node.h"
#ifndef STACK_H
#define STACK_H

typedef struct
{
    Node* top;
    int size;
} Stack;

void initStack(Stack* p)
{
    p->top = NULL;
}

void destroyStack(Stack* p)
{
}

bool isEmpty(Stack* p)
{
    return p->top == NULL ? true : false;
}

int top(Stack* p)
{
    return p->top->dado;
}

void pop(Stack* p)
{
    if (p->top == NULL)
        return;

    Node* tempNode = p->top;
    p->top = tempNode->next;

    free(tempNode);
    p->size--;
}

void makeEmpty(Stack* p)
{
}

void push(Stack* p, int value)
{
    Node* node = createNode(value, p->top);

    if (node != NULL)
    {
        p->top = node;
        p->size++;
    }
}

int topAndPop(Stack* p)
{
}

int size(Stack* p)
{
    return p->size;
}

void printStack(Stack* p)
{
}

#endif