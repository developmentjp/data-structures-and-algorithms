//Doubly Linked List 
#include<stdlib.h>
#include<stdio.h>
#define null NULL
struct Node{
	int data; //4 bytes
	struct Node* next; //4 bytes
	struct Node* prev; //4 bytes
};

struct Node* GetNewNode(int x);
void InsertAtHead(int x);
void InsertAtTail(int x);
void Print();
void ReversePrint();
void Delete(int x);
struct Node* head;
int main(){
	head = null;
//insert at head
//	InsertAtHead(2); Print(); ReversePrint();
//	InsertAtHead(4); Print(); ReversePrint();
//	InsertAtHead(6); Print(); ReversePrint();

//insert at tail
	InsertAtTail(2); Print(); ReversePrint();
	InsertAtTail(4); Print(); ReversePrint();
	InsertAtTail(6); Print(); ReversePrint();
	InsertAtTail(8); Print(); ReversePrint();
	InsertAtTail(10); Print(); ReversePrint();

	int x;
	printf("Enter node to delete: ");
	scanf("%d", &x);
	Delete(x);
	Print();
}

struct Node* GetNewNode(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //c implementation
	newNode->data = x;
	newNode->prev = null; 
	newNode->next = null;
	return newNode;
}
void InsertAtHead(int x){
	struct Node* newNode = GetNewNode(x);
	if(head == null){
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}
void InsertAtTail(int x){
	struct Node* newNode = GetNewNode(x);
	struct Node*temp = head;
	if(head == null){
		head = newNode;
		return;
	}
	// go to last node
	while(temp->next != null){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}
void Print(){
	struct Node*temp = head;
	printf("Forward: ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void ReversePrint(){
	struct Node*temp = head;
	if(temp == null) return; //empty list, exit
	// go to last node
	while(temp->next != null){
		temp = temp->next;
	}
	//traverse backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
//delete node number
void Delete(int x){
	struct Node*temp1 = head;
	struct Node*temp2 = null;
	if(head == null) return;
	if(x == 1){
		temp2 = temp1->next;
		temp1->next = null;
		head = temp2;
		free(temp1);
		return;
	}
	
	for(int i=0; i<x-2; i++){
		temp1 = temp1->next; //temp1 points to (n-1) Node(previous node of the node that will be deleted) 
	}
	
	if(temp1->next != null){
		temp2 = temp1->next;
		if(temp2->next != null){
			temp1->next = temp2->next;
			temp2->next->prev = temp1; //points the prev of (n+1) pointer to (n-1)
			temp2->prev = null;  //points the prev of (n) pointer to null
			temp2->next = null;  //points the next of (n) pointer to null
			free(temp2);
		}else{ //if the next of (n) pointer is null
			temp2->prev = null;
			temp1->next = null;
			free(temp2);
		}
	}
}
