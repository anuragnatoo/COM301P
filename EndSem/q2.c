//Odd Even Sort Multithreaded version
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>
int isSorted=0;
int arr[100];
int n;
int swap(int a,int b)
{
	int temp=a;
	a=b;
	b=temp;
}
void* oddSort(void * arg)
{
	isSorted=1;
	int i;
	for (int i=1; i<=n-2; i=i+2) 
    { 
    	if (arr[i] > arr[i+1]) 
        { 
           	int temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
            isSorted = 0; 
        } 
    } 
}
void* evenSort(void * arg)
{
	isSorted=1;
	int i;
	for (int i=0; i<=n-2; i=i+2) 
    { 
    	if (arr[i] > arr[i+1]) 
        { 
        	int temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
            isSorted = 0; 
        } 
    } 
}
int main(int argc, char *argv[])
{
	int i;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Before Sort: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	pthread_t tid1;
	pthread_t tid2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	while(!isSorted)
	{
		pthread_create(&tid1, &attr, oddSort, NULL);
		pthread_join(tid1, NULL);
		pthread_create(&tid2, &attr, evenSort,NULL);
		pthread_join(tid2, NULL);
	}
	printf("After Sort: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}	
	printf("\n");
}

