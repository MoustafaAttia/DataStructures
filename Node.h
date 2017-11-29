
typedef struct listNode {            
   char data; /* each listNode contains a character */
   struct listNode *nextPtr; /* pointer to next node*/ 
}ListNode;


typedef ListNode *ListNodePtr;


void insert( ListNodePtr *,char );
char deletee( ListNodePtr *,char );
int isEmpty( ListNodePtr );
void printList( ListNodePtr );
void instructions( void );