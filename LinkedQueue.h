
typedef char QueueEntry;

typedef struct queuenode{
	QueueEntry entry;
	struct queuenode *next;
}QueueNode;

typedef struct queue{
	QueueNode *front;
	QueueNode *rear;
	int size;
}Queue;




void CreateQueue(Queue *);
void Append(QueueEntry , Queue *);
void Serve(QueueEntry * , Queue *);
int QueueEmpty(Queue *);
int QueueFull(Queue *);
int QueueSize(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue * , void(*pf)(QueueEntry));
QueueEntry LastElement(Queue *ps);
QueueEntry LastElementRemoved(Queue *ps);
QueueEntry FirstElement(Queue *ps);
void DestroyQueue(Queue *ps);
void CopyQueue(Queue *src,Queue *dest);
int QueueSize(Queue *s);
int QueueSizee(Queue *s);
