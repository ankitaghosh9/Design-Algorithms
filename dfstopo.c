#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int n;

void DFS(int i,int visited[],int a[][n], STACK *p)
{
  int j;
  visited[i]=1;
  for(j=0;j<n;j++)
  {
    if(!visited[j]&&a[i][j]==1)
       DFS(j,visited,a,p);
  }
  push(p,i);
} 
void main()
{
	STACK s;
	s.tos=-1;
  int i,j;
  printf("Enter number of vertices:");
	scanf("%d",&n);
	s.size=n;
  int a[n][n],visited[n];
	printf("Enter adjecency matrix of the graph:\n");
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       {
			  scanf("%d",&a[i][j]);
      }
   for(i=0;i<n;i++)
        visited[i]=0;  
    DFS(0,visited,a, &s);
    for(j=0;j<n;j++)
    {
      if(visited[j]==0)
        DFS(j,visited,a, &s);
    }
    printf("Topological DFS sorting order:\n");
    for(j=0;j<n;j++)
    	printf("%d ",pop(&s));
}

