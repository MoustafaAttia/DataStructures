#include"Stack.h"
#include<stdio.h>

void CreateStack(Stack *ps){
	ps->top = 0;
}

void push(StackEntry e, Stack *ps){
	ps->entry[ps->top] = e;
	ps->top++;
}

int StackFull(Stack *ps)
{
	if(ps->top == MAXSTACK)
		return 1;
	else
		return 0;
}

void pop(StackEntry *pe, Stack *ps){
	ps->top--;
	*pe = ps->entry[ps->top];
}

int StackEmpty(Stack *ps){
	if(ps->top == 0)
		return 1;
	else 
		return 0;
}

void StackTop(StackEntry *pe, Stack *ps){
	*pe = ps->entry[ps->top];
}

int StackSize(Stack *ps){
	return ps->top;
}

void ClearStack(Stack *ps){
	ps->top = 0;
}

void TraverseStack(Stack *ps,void (*pf)(StackEntry)){
	for(int i=ps->top; i>0; i--)
	{
		(*pf)(ps->entry[i-1]);
	}
}

void MakeStack0(Stack *sp)
{
	for(int i = 0; i<sp->top; i++)
		sp->entry[i] = 0;
}

StackEntry FirstElement(Stack *ps)
{
	return ps->entry[0];
}

void CopyStack(Stack *src,Stack *dest)
{
	for(int i=0; i<src->top; i++){
		dest->entry[i] = src->entry[i];
	}
	dest->top = src->top;
}

StackEntry RemoveFirstElement(Stack *ps)
{
	StackEntry temp = ps->entry[0];
	int i;
	for(i = 1; i<MAXSTACK; i++){
		ps->entry[i-1] = ps->entry[i];
	}
	ps->top--;
	return temp;
}