#include<stdio.h>
#include<stdlib.h>
#include"Node.h"

/* Implemention Level */

void instructions(void)
{
	printf("Enter your choice:\n"
		"1- to insert an element into the list.\n"
		"2- to delete an element from the list.\n"
		"3- to end.\n");
}

/* insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, char value )
{
	ListNodePtr newPtr;      /* pointer to new node */
    ListNodePtr previousPtr; /* pointer to previous node in list */
    ListNodePtr currentPtr;  /* pointer to current node in list */

	newPtr = (ListNode*)malloc(sizeof(ListNode)); /* create node */

	if( newPtr != NULL ){
		newPtr->data = value; /* place value in the node */
		newPtr->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

		/* loop to find the correct location in the list */
		while( currentPtr != NULL && value > currentPtr->data) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		/* insert new node at beginning of the list */
		if( previousPtr == NULL ){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else { /* insert new node between previousPtr and currentPtr */
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
		else {
			printf("%c is not inserted. No memory avalibale.\n",value);
		}
	}

/* Delete a list element */
char deletee( ListNodePtr *sPtr,char value )
{
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr; /* temporary node pointer */

	/* delete first node */

	if( value == (*sPtr)->data){
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr;
		tempPtr = NULL;
		return value;
	}
	else {
		previousPtr = *sPtr;
		currentPtr = ( *sPtr )->nextPtr;

		/* loop to find the correct location in the list */
		while( currentPtr != NULL && currentPtr->data != value ) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		/* delete node at currentPtr */
		if( currentPtr != NULL ){
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			tempPtr = NULL;
			return value;
		}
	}

	return '\0';
}

/* return 1 if the list is Empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{
	return sPtr == NULL;
}

void printList( ListNodePtr currentPtr )
{
	/* if list is Empty */
	if( currentPtr == NULL ) {
		printf("List is Empty.\n\n");
	}
	else {
		printf("The list is: \n");

	/* whole not the end of the list */
		while( currentPtr != NULL ) {
			printf("%c --> ",currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		printf("NULL \n\n" );
	}
}