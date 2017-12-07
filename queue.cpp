#include"queue.h"

/* this is implemention Level */

void CreateQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}

void Append(QueueEntry e , Queue *pq)
{
	pq->rear = (pq->rear+1) % MAXQUEUE;
	pq->entry[pq->rear] = e;
	pq->size++;
}

void Serve(QueueEntry *pe , Queue *pq)
{
	*pe = pq->entry[pq->front];
	pq->front = (pq->front+1) % MAXQUEUE;
	pq->size--;
}

int QueueEmpty(Queue *pq)
{
	return (!pq->size);
}

int QueueFull(Queue *pq)
{
	return (pq->size == MAXQUEUE);
}

int QueueSize(Queue *pq)
{
	return pq->size;
}

void ClearQueue(Queue *pq)
{
	pq->front = 0;
	pq->rear = -1;
	pq->size = 0;
}

void TraverseQueue(Queue *pq , void(*pf)(QueueEntry))
{
	int pos , s;
	for(pos=pq->front , s=0; s<pq->size; s++){
		(pf)(pq->entry[pos]);
		pos = (pos+1) % MAXQUEUE;
	}
}

QueueEntry FirstElement(Queue *ps)
{
	return ps->entry[ps->front];
}

QueueEntry LastElement(Queue *ps)
{
	return ps->entry[ps->rear];
}

QueueEntry LastElementRemoved(Queue *ps)
{
	QueueEntry result;
	result = ps->entry[ps->rear];
	if(ps->rear == 0)
		ps->rear = MAXQUEUE-1;
	else
	{
		ps->rear--;
		ps->size--;
		return result;
	}
}

void CopyQueue(Queue *src,Queue *dest)
{
	int pos;
	int s;
	for(pos=src->front , s=0; s<src->size; s++){
		dest->entry[pos] = src->entry[pos];
		pos = (pos+1) % MAXQUEUE;
	}
	dest->front = src->front;
	dest->rear = src->rear;
	dest->size = src->size;
}