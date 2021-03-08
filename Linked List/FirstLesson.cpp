//Linked List
//address of the head node give us acces to the complete list
//traversing start from the head
//time taken to access elements: t-> n or O(n)
//Insertion/Deletion: O(n)


//Linked List Insert at Beginning
#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data; //4 bytes
	struct Node* next; //4 bytes
};

struct Node* head; //global variable, can be accessed anywhere
void Insert(int x);
void Print();
int main(){
	head = NULL; //list is empty, points nowhere
	printf("How many numbers?\n");
	int n,i,x;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter the number\n");
		scanf("%d", &x);
		Insert(x);
		Print();
	}
}

void Insert(int x){ 
	struct Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	head = temp;
}

void Print(){
	struct Node*temp = head;
	printf("List is: ");
	while(temp != NULL){
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
