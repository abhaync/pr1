//Quick Sort
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

#define MAX 10000

double clock()
{
	struct timeval tv;

}

int main()
{
    int arr[100],n,i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++) {
        printf("%d",arr[i]);
    }
    return 0;
}
