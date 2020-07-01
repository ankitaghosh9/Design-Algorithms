#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{
	int data;
	nodeptr lchild;
	nodeptr rchild;
	int balancefact;
};
nodeptr getnode()
{
	nodeptr temp;
	temp=(nodeptr)malloc(sizeof(struct node));
	return temp;
}
nodeptr insert(nodeptr root,int item)
{
	nodeptr temp;
	if(root==NULL)
	{
		temp=getnode();
		
		temp->data=item;
		temp->lchild=temp->rchild=NULL;
		 return temp;
	}
	else
	{
		if(item<root->data)
			root->lchild=insert(root->lchild,item);
		else
			if(item>root->data)
			root->rchild=insert(root->rchild,item);
		else
			printf("Dont enter duplicates");
		return root;
		
    }
}
int max(int a,int b)
{
	int max;
	if(a>b)
		max=a;
	else
		max=b;
	return max;

}
int height(nodeptr root)
{
	int count=0;
	if((root)==NULL)
		return 0;
return(1+max(height(root->lchild),height(root->rchild)));

}
void balancefact(nodeptr root)
{
	
 if((root)==NULL)
  return;
root->balancefact=height(root->lchild)-height(root->rchild);

balancefact(root->lchild);
balancefact(root->rchild);

}
void inorder(nodeptr root)
{
	if(root)
	{
		inorder(root->lchild);
		printf("%d\n",root->balancefact);
		inorder(root->rchild);
	}

}
int main()
{
	nodeptr root;
	root=NULL;
    int choice,se,item;
	printf("Insert nodes");
	scanf("%d",&item);
	while(item!=-1)
	{
	        
			root=insert(root,item);
			printf("Enter element to insert\n");
			scanf("%d",&item);
	}
	balancefact(root);
	inorder(root);
}