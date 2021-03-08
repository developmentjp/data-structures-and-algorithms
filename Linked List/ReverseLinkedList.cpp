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
void Reverse();  //Reverse nodes
int main(){
	head = NULL; //list is empty, points nowhere
	Insert(2, 1); //List: 2
	Insert(4, 2); //List: 2,4
	Insert(6, 3); //List: 2,4,6
	Insert(5, 4); //List: 2,4,6,5
	printf("All nodes are here\n");
	Print();
	Reverse();
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

void Reverse(){
	if(head == NULL) return;
	struct Node*current = head;
	struct Node*prev = NULL;
	struct Node*next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;	
	}
	head = prev;
	prev = NULL;
	free(prev);
	free(next);
	free(current);
}


