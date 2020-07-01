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

int main(){
STACK st1;
st1.size=100;
st1.tos=-1;
int n=0;
int x;
printf("1.Push 2.Pop 3.Display 4.Exit\n");
while(n!=4){
scanf("%d",&n);
switch(n){
case 1: 
printf("Enter x:");
scanf("%d",&x);
push(&st1,x);
break;
case 2:
printf("%d\n",pop(&st1));
break;
case 3:
disp(&st1);
printf("\n");
break;
default:
printf("Exiting..");
}
}
}