//Linked List reverse using recursion
#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data; //4 bytes
	struct Node* next; //4 bytes
};

struct Node* head; //global variable, can be accessed anywhere
void Insert(int data, int n);
void Print(struct Node*p);
void Reverse(struct Node*p);  //reverse list
int main(){
	head = NULL; //list is empty, points nowhere
	Insert(2, 1); //List: 2
	Insert(4, 2); //List: 2,4
	Insert(6, 3); //List: 2,4,6
	Insert(5, 4); //List: 2,4,6,5
	printf("All nodes are here\n");
	Print(head);
	printf("\n");
	Reverse(head);
	Print(head);
}

void Insert(int data, int n){ 
	Node* temp1 = new Node(); //c++ way for malloc
	temp1->data = data;
	temp1->next = NULL;
	if(n == 1){
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for( int i=0; i<n-2; i++){
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
// iterative approach is much more efficient, we will not waste memory in stack of the computer when calling more functions
void Print(struct Node*p){
	//print normally
	if(p == NULL) return; //return condition
	printf("%d ", p->data); //print first the value
	Print(p->next); //recursive call
	
}

void Reverse(struct Node*p){
	if(p->next ==NULL){
		head = p; //make the head point to the last node
		return;
	}
	Reverse(p->next);
	struct Node*q = p->next;
	q->next = p;
	p->next = NULL;	
	// 3 lines of code above can  be like p->next->next = p;
}

// questions
// what if head is not a global variable?

