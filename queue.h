
#define MAXQUEUE 10

typedef char QueueEntry;

typedef struct Queue{
	int rear;
	int front;
	int size;
	QueueEntry entry[MAXQUEUE];
}Queue;

void CreateQueue(Queue *);
void Append(QueueEntry , Queue *);
void Serve(QueueEntry * , Queue *);
int QueueEmpty(Queue *);
int QueueFull(Queue *);
int QueueSize(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue * , void(*pf)(QueueEntry));
QueueEntry FirstElement(Queue *);
QueueEntry LastElement(Queue *);
QueueEntry LastElementRemoved(Queue *);
void CopyQueue(Queue *src,Queue *dest);