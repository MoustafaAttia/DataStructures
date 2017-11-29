#include<stdio.h>
#include<stdlib.h>
#include"Node.h"

/* this program from Dietel Book "C How To Program" at page 482-487 */

int main()
{
	ListNodePtr startPtr = NULL;
	int choice;
	char item;

	instructions();
	printf("? ");
	scanf("%d",&choice);

	/* loop while user does not choose 3 */

	while(choice != 3){
		switch(choice){
		case 1:
			printf("Enter a character: ");
			scanf("\n%c",&item);
			insert(&startPtr,item); /* insert item to the list*/
			printList(startPtr);
			break;

		case 2: /* delete an item */
				/* if a list is not empt */
			if(!isEmpty(startPtr) ){
				printf("Enter character to be deleted: ");
				scanf("\n%c",&item);
				/* if a character is found, remove it */
				if( deletee(&startPtr,item) ) { /* remove item */
					printf("%c deleted. \n",item);
					printList( startPtr);

				}
				else {
					printf("%c is not found. \n\n",item);
				}
			} /* end of if for isEmpty */
			break;

		default:
			printf(" Invalid choice. \n\n");
			instructions();
			break;
		} /* end of switch */

		printf("? ");
		scanf("%d", &choice);
	} /* end while */

	printf("End of run. \n");

	return 0;
} /* end main */