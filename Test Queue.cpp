#include<stdio.h>
#include"LinkedQueue.h"


/* This is user level */

void PrintQueue(QueueEntry pe)
{
	printf("%c <--",pe);
}


int main()
{
	printf("********************************************\n"
		"This Queue is just for CHAR onlyyyyyyyy \n"
		"********************************************\n");
	Queue q;
	int j = 0;
	QueueEntry e;
	char arr[10] = {'A','B','C','D','E','F','G','H','I','J'};
	CreateQueue(&q);

	for(int i=0; i<10; i++)
	{
		e = arr[i];
		Append(e,&q);
		TraverseQueue(&q , &PrintQueue);
		putchar('\n');
	}
	
	printf("_______________________________________________________\n");
	printf("The orignal Queue is like that : \n");
	TraverseQueue(&q , &PrintQueue);
	putchar('\n');
	printf("_______________________________________________________\n");
	printf("The first element in the queue is %c: \n",FirstElement(&q));
	putchar('\n');


	while(!QueueEmpty(&q))
	{
		Serve(&e , &q);
		printf("After we Serve the elemnt number %d\n",(10-j));
		TraverseQueue(&q , &PrintQueue);
		putchar('\n');
		printf("The element e = '%c'\n",e);
		printf("******\nThe Size of Queue now is : %d\n", QueueSize(&q));
		printf("_______________________________________________________\n");
		j++;
	}

	QueueEntry item = NULL;
	Queue write;
	CreateQueue(&write);

	while(item != '\n')
	{
		Append(item , &write);
		scanf("%c",&item);
	}
	printf("__________________________________________________\n");
	TraverseQueue(&write , &PrintQueue);
	
	putchar('\n');

	return 0;
}
