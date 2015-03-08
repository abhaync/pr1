#include<stdio.h>
#include<stdlib.h>
#define INF 999
int a[10][10],d[10],pred[10];
void init(int s, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		d[i]=INF;
		pred[i]=-1;
	}
	d[s]=0;
}
void relax(int u, int v, int w)
{
	if(d[v]>(d[u]+a[u][v]))
	{
		d[v]=d[u]+a[u][v];
		pred[v]=u;
	}
}
int negcycle(int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(d[j]>(d[i]+a[i][j]))
				return 0;
		}
	}
	return 1;
}
void main()
{
	int i,j,n,ch,p;
	printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency cost matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the source vertex\n");
	scanf("%d",&ch);
	init(ch,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			relax(i,j,a[i][j]);
		}
	}
	printf("The Distance array is \n");
	for(i=0;i<n;i++)
		printf("%d\t",d[i]);
	printf("\n");
	printf("The Predecessor array is \n");
	for(i=0;i<n;i++)
		printf("%d\t",pred[i]);
	printf("\n");
	p=negcycle(n);
	if(p==1)
	{
		printf("No Negative weight Cycle\n");
	}
	else
	{
		printf("Negative Weight Cycle Present\n");
	}

}
