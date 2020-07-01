#include <stdio.h>
#include <stdlib.h>

int n;

int sourceremoval(int a[][n], int ans[], int k)
{
	int visited[n];
	for(int j=0;j<n;j++)
		visited[j]=0;

	int k2=k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			visited[i]+=a[j][i];
		}
		printf("%d ",visited[i]);
	}
	printf("\n");

    for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			ans[k]=i;
			a[i][i]=1;
			for(int j=0;j<n;j++)
			{
				a[i][j]==0;
			}
			k++;
			break;
		}
	}

	for(int i=0;i<n;i++)
       {for(int j=0;j<n;j++)
       	 printf("%d",a[i][j]);

       	printf("\n");
       }
       printf("\n");

	return k;
}

void main()
{
	printf("Enter number of vertices:");
	scanf("%d",&n);
	int a[n][n],visited[n], ans[n];
	printf("Enter adjecency matrix of the graph:\n");
	for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
       	 scanf("%d",&a[i][j]);

     int x=0;
    for(int i=0;i<n;i++)
    {
    	x=sourceremoval(a,ans,i);
    	if(x==i)
    	{
    		printf("Sorting not possible\n");
    		break;
    	}
    }
    if(x==n)
    {
     for(int i=0;i<n;i++)
     	printf("%d ",ans[i]);
    }



}