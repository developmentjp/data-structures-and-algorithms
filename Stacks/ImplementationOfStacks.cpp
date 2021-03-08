//Implementation of Stacks <Array_Based>
//empty stack top << -1
//Stack ADT (Last in First Out LIFO) 
#include<stdlib.h>
#include<stdio.h>
#define null NULL

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1; //intiating top is empty

void Push(int x);
void Pop();
int Top();
void Print();
int main(){
	Push(2); Print();
	Push(5); Print();
	Push(10); Print();
	Pop(); Print();
	Push(12); Print();
}

void Push(int x){
	if(top == MAX_SIZE -1){ //prevent overflow
		printf("Error: stackoverflow\n");
		return;
	}
	A[++top] = x; //increment happen before assignment
}

void Pop(){
	if(top == -1){
		printf("Error: no element to pop\n");
		return;
	}
	printf("Popping: %d\n", A[top]);
	top--;
}

int Top(){
	return A[top];
}

void Print(){
	int i;
	printf("Stack: ");
	for(i=0; i<=top; i++){
		printf("%d ", A[i]);
	}
		printf("\n");
}
