#include<stdlib.h>
#include"LinkedQueue.h"

/* This is implemention level */

void CreateQueue(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->size = 0;
}

void Append(QueueEntry e , Queue *pq)
{
	QueueNode *pn = (QueueNode*)malloc( sizeof(QueueNode) );
	pn->next = NULL;
	pn->entry = e;
	if(!pq->rear)
		pq->front = pn;
	else
	pq->rear->next = pn;
	pq->rear = pn;
	pq->size++;
}

void Serve(QueueEntry *pe , Queue *pq)
{
	QueueNode *pn = pq->front;
	*pe = pn->entry;
	pq->front = pn->next; // change it to pq->front = pq->front->next
	free(pn);
	if(!pq->rear)
		pq->rear = NULL;
	pq->size--;
}

int QueueEmpty(Queue *pq)
{
	return !pq->front; // try to to change it to pq->rear
}

int QueueFull(Queue *pq)
{
	return 0;
}

int QueueSize(Queue *pq)
{
	return pq->size;
}

void ClearQueue(Queue *pq)
{
	while(pq->front){
		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->size = 0;
}

void TraverseQueue(Queue *pq , void(*pf)(QueueEntry))
{
	QueueNode *pn;
	for(pn=pq->front; pn; pn=pn->next)
		(*pf)(pn->entry);
}

QueueEntry LastElement(Queue *ps)
{
	return ps->rear->entry;
}

QueueEntry LastElementRemoved(Queue *ps)
{
	QueueNode *pn;
	QueueEntry result;
	result = ps->rear->entry;
	pn = ps->front;
	if(pn->next == NULL){
		result = pn->entry;
		free(pn);
		ps->front = NULL;
		return result;
	}
	else
	{
	while(pn->next->next != NULL)
	{
		pn = pn->next;
	}

	free(ps->rear);
	ps->rear = pn;
	ps->rear->next = NULL;
	ps->size--;
	}
	return result;
}

QueueEntry FirstElement(Queue *ps)
{
	return ps->front->entry;
}

int QueueSizee(Queue *s)
{
	int result = 0;
	QueueNode *pn;
	pn = s->front;
	while(pn){
		result++;
		pn = pn->next;
	}
	return result;
}