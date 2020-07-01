#include <stdio.h>
#include <stdlib.h>

typedef struct {
int arr[100];
int tos;
int size;
} STACK;

int isEmpty(STACK *p){
if(p->tos==-1)
return 1;
return 0; 
}

int isFull(STACK *p){
if(p->tos==p->size-1)
return 1;
return 0; 
}

int pop(STACK *p){
if(!isEmpty(p)){
return p->arr[p->tos--];
}
else{
printf("Underflow..");
	return '\0';
}
}

void push(STACK *p, int x){
if(!isFull(p)){
p->arr[++p->tos]=x;
}
else{
printf("Overflow..");
}
}

void disp(STACK *p)
{
int n=0;
while(n<=p->tos){
printf("%d ",p->arr[n++]);
}
}