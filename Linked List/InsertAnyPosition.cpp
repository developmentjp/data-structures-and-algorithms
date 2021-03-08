//Linked List Insert at n position
#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data; //4 bytes
	struct Node* next; //4 bytes
};

struct Node* head; //global variable, can be accessed anywhere
void Insert(int data, int n);
void Print();
int main(){
	head = NULL; //list is empty, points nowhere
	Insert(2, 1); //List: 2
	Insert(3, 2); //List: 2,3
	Insert(4, 1); //List: 4,2,3
	Insert(5, 2); //List: 4,5,2,3
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
