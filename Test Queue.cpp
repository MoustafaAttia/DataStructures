#include<stdio.h>
#include"queue.h"
#include<string.h>


/* This is user level */

void PrintQueue(QueueEntry pe)
{
	printf("%c <--",pe);
}

QueueEntry LastElement2(Queue *ps)
{
    Queue temp;
    CreateQueue(&temp);
    QueueEntry item , result;
    while(!QueueEmpty(ps)){
        Serve(&item , ps);
        Append(item , &temp);
    }
    result = item;
    while(!QueueEmpty(&temp)){
        Serve(&item , &temp);
        Append(item , ps);
    }
    return result;
}

QueueEntry LastElementRemoved2(Queue *ps)
{
	Queue temp;
    CreateQueue(&temp);
    QueueEntry item , result;
	int counter = 0;
	int i;
    while(!QueueEmpty(ps)){
        Serve(&item , ps);
        Append(item , &temp);
		counter++;
    }
    result = item;
	for(i=1; i<counter; i++){
        Serve(&item , &temp);
        Append(item , ps);
    }
    return result;
}

QueueEntry FirstElement2(Queue *ps)
{
	Queue temp;
	QueueEntry result , item;
	CreateQueue(&temp);
	Serve(&item , ps);
	Append(item , &temp);
	result = item;
	while(!QueueEmpty(ps)){
        Serve(&item , ps);
        Append(item , &temp);
    }
	while(!QueueEmpty(&temp)){
		Serve(&item , &temp);
        Append(item , ps);
	}
	return result;
}

void DestroyQueue(Queue *ps)
{
	QueueEntry item;
	while(!QueueEmpty(ps)){
		Serve(&item , ps);
	}
}

void CopyQueue2(Queue *src,Queue *dest)
{
	QueueEntry item;
	Queue temp;
	CreateQueue(&temp);
	while(!QueueEmpty(src)){
        Serve(&item , src);
        Append(item , dest);
		Append(item , &temp);
    }
	while(!QueueEmpty(&temp)){
		Serve(&item , &temp);
		Append(item , src);
	}
}

int QueueSize2(Queue *s)
{
	int result = 0;
	QueueEntry item;
	Queue temp;
	CreateQueue(&temp);
	while(!QueueEmpty(s)){
		Serve(&item , s);
		Append(item , &temp);
		result++;
	}
	while(!QueueEmpty(&temp)){
		Serve(&item , &temp);
		Append(item , s);
	}
	return result;
}

int main()
{
	printf("********************************************\n"
		"This Queue is just for CHAR only \n"
		"********************************************\n");
	Queue q , t;
	QueueEntry e;
	char arr[10] = {'A','B','C','D','E','F','G','H','I','J'};
	int i = 0 , j = 0;
	CreateQueue(&q);
	CreateQueue(&t);

	while(!QueueFull(&q))
	{
		e = arr[i];
		Append(e,&q);
		TraverseQueue(&q , &PrintQueue);
		putchar('\n');
		i++;
	}
	
	printf("_______________________________________________________\n");
	printf("The orignal Queue is like that : \n");
	TraverseQueue(&q , &PrintQueue);
	putchar('\n');
	printf("_______________________________________________________\n");
	CopyQueue2(&q , &t);
	printf("The queue t is like that : \n");
	TraverseQueue(&t , &PrintQueue);
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

	QueueEntry item;
	Queue write;
	CreateQueue(&write);

	while(!QueueFull(&write))
	{
		scanf("%c",&item);
		Append(item , &write);
	}
	printf("__________________________________________________\n");
	TraverseQueue(&write , &PrintQueue);
	
	putchar('\n');

	return 0;
}
