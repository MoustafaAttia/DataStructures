#include<stdio.h>
#include"Stack.h"


/* This is user level */

void PrintStack(StackEntry pe)
{
	printf("%c <--",pe);
}

StackEntry FirstElement2(Stack *ps)
{
	Stack temp;
	CreateStack(&temp);
	StackEntry item , result;
	while(!StackEmpty(ps)){
		pop(&item , ps);
		push(item , &temp);
	}
	result = item;
	while(!StackEmpty(&temp)){
		pop(&item , &temp);
		push(item , ps);
	}

	return result;
}

StackEntry LastElement2(Stack *ps)
{
	StackEntry result;
	pop(&result , ps);
	push(result , ps);

	return result;
}

void DestroyStack(Stack *ps)
{
	StackEntry item;
	while(!StackEmpty(ps)){
		pop(&item , ps);
	}
}

void CopyStack2(Stack *src,Stack *dest){
	Stack temp;
	StackEntry item;

	CreateStack(&temp);
	while(!StackEmpty(src)){
		pop(&item , src);
		push(item , &temp);
	}
	while(!StackEmpty(&temp)){
		pop(&item , &temp);
		push(item , dest);
		push(item , src);
	}

}

int StackSize2(Stack *s)
{
	int counter = 0;
	Stack temp;
	StackEntry item;
	CreateStack(&temp);

	while(!StackEmpty(s))
	{
		pop(&item , s);
		push(item , &temp);
		counter++;
	}

	while(!StackEmpty(&temp)){
		pop(&item , &temp);
		push(item , s);
	}

	return counter;
}

StackEntry RemoveFirstElement2(Stack *ps)
{
	Stack temp;
	CreateStack(&temp);
	StackEntry item , result;

	while(!StackEmpty(ps)){
		pop(&item , ps);
		push(item , &temp);
	}
	result = item;
	pop(&item , &temp);
	while(!StackEmpty(&temp)){
		pop(&item , &temp);
		push(item , ps);
	}

	return result;
}

int main()
{
	printf("********************************************\n"
		"This Stack is just for CHAR only \n"
		"********************************************\n");
	Stack s;
	StackEntry e;
	char arr[10] = {'A','B','C','D','E','F','G','H','I','J'};
	CreateStack(&s);

	for(int i=0; i<10; i++)
	{
		e = arr[i];
		push(e,&s);
		TraverseStack(&s , &PrintStack);
		putchar('\n');
	}
	
	printf("_______________________________________________________\n");
	printf("The orignal Stack is like that : \n");
	TraverseStack(&s , &PrintStack);
	putchar('\n');
	printf("_______________________________________________________\n");
	

	for(int i=0; i<10; i++)
	{
		pop(&e , &s);
		printf("After we pop the elemnt number %d\n",(10-i));
		TraverseStack(&s , &PrintStack);
		putchar('\n');
		printf("The element e = '%c'\n",e);
		printf("_______________________________________________________\n");
	}

	StackEntry item;
	Stack stack;
	CreateStack(&stack);

	for(int i=0;i<5;i++)
	{
		scanf("%c",&item);
		push(item , &stack);
	}
	printf("__________________________________________________\n");
	TraverseStack(&stack , &PrintStack);
	
	putchar('\n');

	return 0;
}
