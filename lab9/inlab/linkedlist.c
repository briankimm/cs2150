//Brian Kim, byk6q, linkedlist.c, 11/16/21
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define PUSH_FRONT 	0
#define PUSH_BACK 	1
#define POP_FRONT 	2
#define POP_BACK 	3
#define PRINT_LIST 	4
#define HELP 		5
#define QUIT 		6
#define INVALID 	7

#define BUFFER_SIZE 20

void printOptions();
int readInput(int* val);
int isNumber(const char* token);
int isEmpty(const char* input);

int main(){

	// TODO: INSTANTIATE YOUR LINKED LIST HERE.
  struct list_item{
    struct list_item* p;//previous
    struct list_item* n;//next
    int value;//value of node
  };

  //instantiates head and tail
  struct list_item* head = malloc(sizeof(struct list_item));
  struct list_item* tail = malloc(sizeof(struct list_item));

  //sets head's and tail's previous and next
  head -> n = tail;
  head -> p = NULL;
  tail -> p = head;
  tail -> n = NULL;

	//----END----
	

	int option, val;
	printOptions();

	do {
		option = readInput(&val);
		struct list_item* node;//new node

		switch(option){

		  //SAME PROCESS AS LAB 2 IN TERMS OF POINTERS
			case PUSH_FRONT:				// push onto front of list
				// TODO: Insert code to push val onto front of linked list here.
			  node = malloc(sizeof(struct list_item));
			  node->value = val;//value of node is set to val
			  node->n = head ->n;//nodes next is set to heads next
			  node->n->p= node;//sets node's next's previous equal to node
			  node ->p = head;//node previous is now head
			  head -> n= node;//head's next is now node
				//----END----
				break;
			case PUSH_BACK: 				// push onto back of list
				// TODO: Insert code to push val onto back of linked list here.
			  node = malloc(sizeof(struct list_item));
					node -> value = val;
					node -> n = tail;//nodes next is tail
					node -> p = tail -> p;//nodes previous is tails previous
					tail -> p = node;//tail previous is now node
					node ->p ->n = node;//node's previous' next is node
				//----END----
				break;
			case POP_FRONT: 				// remove from front of list
				// TODO: Insert code to remove from front of linked list here.
				// If list is empty, do nothing.
			  if(head -> n != tail){//checks to see if it empty
			    node = head -> n;//node is set
			    head -> n = head ->n -> n;//sets head next to node's old next
			    head -> n -> p = head;//sets head's next's previous to head
					}
			  free(node);//delete node

							   

				//----END----
				break;
			case POP_BACK:					// remove from back of list
				// TODO: Insert code to remove from back of linked list here.
				// If list is empty, do nothing.
			  if(head -> n != tail){//checks to see if empty
			    node = tail -> p;//sets node
			    tail ->p = tail -> p -> p;//sets tail previous to nodes old previous
			    tail -> p -> n = tail;//tail's previous' next is tail
					}
			  free(node);//deallocate

				//----END----
				break;
			case PRINT_LIST:				// print list
				// TODO: Insert code to print list forwards here.
				// Simply print each element separated by a space as shown below:
				// Elements: 1 2 3 4 5 
				printf("Elements: ");
				node = head ->n;//sets node
				while(node -> n != NULL){//checks to see if at the end
				  printf(" %d", node->value);//prints int of node-> value
				  node = node ->n;//sets node to the next node in linked list
					}
					printf("\n");


				//----END----
				break;
			case HELP: 						// print menu
				printOptions();
				break;
			case QUIT: 						// quit
				break;
			case INVALID: 					// bad input
				fprintf(stderr,"Invalid command or operand, please input a valid command or help to see the list again.\n");
				break;
		}

	} while(option != QUIT);

	// TODO: free any memory used by your linked list here
	struct list_item* node;//instantiates node
	while(head->n != tail){//checks to see if we are at the end
		  node = malloc(sizeof(struct list_item));
		  node = head ->n;//sets node
		  head -> n = head -> n -> n;//taken from POP_FRONT 
		  head ->n -> p = head;
		  free(node);
		}
	free(head);//delete head
	free(tail);//delete tail
	//----END----

	return 0;
}



//---------------------------------------
//NOTE: EVERYTHING BELOW THIS LINE SHOULD NOT BE TOUCHED. IT HANDLES INPUT AND SUCH FOR YOU
//---------------------------------------

int readInput(int* val){
	char input[BUFFER_SIZE]="";
	while(isEmpty(input)){
		printf("Enter command: ");
		fgets(input, BUFFER_SIZE, stdin);
		input[strcspn(input, "\n")] = 0;
	}

	char* token = strtok(input, " ");
	
	if ((strcmp(token, "af")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_FRONT;
		} else return INVALID;
	} else if ((strcmp(token, "ab")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_BACK;
		} else return INVALID;
	} else if ((strcmp(token, "rf")) == 0){
	 	return POP_FRONT;
	} else if ((strcmp(token, "rb")) == 0){
	 	return POP_BACK;
	} else if ((strcmp(token, "p")) == 0){
	 	return PRINT_LIST;
	} else if((strcmp(token, "help")) == 0){
	 	return HELP;
	} else if((strcmp(token, "-1")) == 0){
	 	return QUIT;
	} else {
		return INVALID;
	}
}

void printOptions(){
	printf("----------------------------------------------------\n");
	printf("This test harness operates with one linked list.\n");
	printf("Use any of the following options to manipulate it:\n");
	printf("\t* af <num> --- add integer to front\n");
	printf("\t* ab <num> --- add integer to back\n");
	printf("\t* rf       --- remove front element\n");
	printf("\t* rb       --- remove back element\n");
	printf("\t* p        --- print list forward\n");
	printf("\t* help     --- print off this list\n");
	printf("\t* -1       --- exit harness\n\n");
}

int isNumber(const char* token){
	int length, i = 0;
	if (token == NULL)	return 0;
	if(token[0] == '-') 	i = 1;
	length = strlen(token);
	for (; i < length; i++){
	    if (!isdigit(token[i]))
	    	return 0;
	}

	return 1;
}

int isEmpty(const char* input){
	while (*input != '\0'){
		if (!isspace((unsigned char)*input))
			return 0;
		input++;
	}

	return 1;
}
 
