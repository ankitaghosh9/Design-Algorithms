#include <stdio.h>
#include <stdlib.h>

typedef struct node *Nodeptr;
typedef struct node
{
	int data;
	Nodeptr rchild;
	Nodeptr lchild;
}Node;

Nodeptr getNode()
{
	Nodeptr temp=(Nodeptr)malloc(sizeof(Node));
	temp->rchild=NULL;
	temp->lchild=NULL;
	return temp;
}

Nodeptr create()
{
	Nodeptr root;
	int x;
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	root=getNode();
	root->data=x;
	
	printf("Enter left child of %d:",x);
	root->lchild=create();
 
	printf("Enter right child of %d:",x);
	root->rchild=create();
	
	return root;
}

void inorder(Nodeptr p)
{
	if(p!=NULL)
	{
		inorder(p->lchild);
		printf("%d ",p->data);
		inorder(p->rchild);
	}
}

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int height(Nodeptr p)
{
	if(p==NULL)
		return 0;

	int a=height(p->lchild);
	int b=height(p->rchild);
	return 1+ max(a,b);
}

int diameter(Nodeptr p)
{
	if(!p)
		return 0;

    int a=height(p->lchild);
	int b=height(p->rchild);
	int dl=diameter(p->lchild);
	int dr=diameter(p->rchild);

	return max(a+b+1,max(dl,dr));
}

int main()
{
	printf("Enter data(-1 for no data):");
	Nodeptr root=create();
	inorder(root);
	printf("\n");
	int h=height(root);
	printf("Height: %d\n",h);
	int d=diameter(root);
	printf("Diameter: %d\n",d);
}
