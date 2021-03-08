//Linked List delete at n position
#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data; //4 bytes
	struct Node* next; //4 bytes
};

struct Node* head; //global variable, can be accessed anywhere
void Insert(int data, int n);
void Print();
void Delete(int n);  //delete node
int main(){
	head = NULL; //list is empty, points nowhere
	Insert(2, 1); //List: 2
	Insert(4, 2); //List: 2,4
	Insert(6, 3); //List: 2,4,6
	Insert(5, 4); //List: 2,4,6,5
	printf("All nodes are here\n");
	Print();
	int n;
	printf("\nEnter n position to delete\n");
	scanf("%d", &n);
	Delete(n);
	Print();
	
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

void Print(){
	struct Node*temp = head;
	printf("List is: ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Delete(int n){
	struct Node* temp1 = head;
	int i;
	if(n == 1){
		head = temp1->next; // if delete n is head, head now points to second node
		free(temp1); // free the first node
		return; //to prevent the statements below from performing
	}
	for(i=0; i<n-2; i++){
		temp1 = temp1->next;//temp1 points to (n-1) Node	
	}
	struct Node* temp2 = temp1->next; //nth node
	temp1->next = temp2->next; //(n+1)th node
	free(temp2); // free memory allocation
}



