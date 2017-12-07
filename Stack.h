#define MAXSTACK 10

typedef char StackEntry;

typedef struct stack{
	int top;
	StackEntry entry[MAXSTACK];
}Stack;


	
	void push(StackEntry, Stack *); // done
	void pop(StackEntry *, Stack *);  // done
	int StackEmpty(Stack *);  // done
	int StackFull(Stack *); // done
	void CreateStack(Stack *);  // done
	void StackTop(StackEntry *,Stack *); // done
	int StackSize(Stack *);   // done
	void ClearStack(Stack *); // done
	void TraverseStack(Stack *,void (*)(StackEntry)); // done
	void PrintStack(Stack *);
	void MakeStack0(Stack *);
	StackEntry FirstElement(Stack *ps);
	void CopyStack(Stack *src,Stack *dest);
	StackEntry RemoveFirstElement(Stack *ps);