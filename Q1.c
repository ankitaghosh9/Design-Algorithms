#include<stdio.h>
#include<stdlib.h>
int opcount=0;

int assignment(int n,int C[][n])
{
	int p[n],fix[n];
	int sum=TMP_MAX,sumtemp,temp;
	for(int i=0;i<n;i++)
		p[i]=i;
	for (int j = 1; j <= n; j++)
	{
		for (int i = 0; i < n-1; i++)
		{	opcount++;
            temp = p[i];
            p[i] = p[i+1];
            p[i+1] = temp;     
            sumtemp=0;
            for(int k=0;k<n;k++)
	        	sumtemp+=C[k][p[k]];
	       	if(sum>sumtemp)
	       {
	           sum=sumtemp;
	           for(int k=0;k<n;k++)
	           	fix[k]=p[k];
	       }
		}
	}	
	printf("Person:\t");
	for(int i=0;i<n;i++)
		printf("%d\t",i+1);
	printf("\nJob:\t");
	for(int i=0;i<n;i++)
		printf("%d\t",fix[i]+1);
	printf("\nSum = %d",sum);
}

int main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int C[n][n];
	printf("Enter cost matrix: ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("\nEnter cost for person %d and job %d: ",i+1,j+1);
			scanf("%d",&C[i][j]);
		}
	}
	printf("\nCost Matrix\n");
	for(int i=0;i<n;i++)
		printf("\t%d",i+1);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",i+1);
		for(int j=0;j<n;j++)
			printf("%d\t",C[i][j]);
		printf("\n");
	}
	assignment(n,C);
	printf("\nOperation Count: %d",opcount);
}