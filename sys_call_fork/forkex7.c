#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int SIZE=5;
int a[5];
void reads(int SIZE)
{    
	printf("Enter 5 numbers\n");
    for(int i=0 ; i<SIZE ; ++i)
    {
        scanf("%d",&a[i]);
    }
}
int partition(int beg,int end)
{
    int i = beg;
    int j = end;
    int pivot = a[beg];
    while (i <= j)
    {
        while (a[i] <= pivot && i <= end)
        {
            i++;
        }
        while (a[j] > pivot && j > beg)
        {
            j--;
        }
        int temp;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[beg];
    a[beg] = a[j];
    a[j] = temp;
    return j;
}
void print(int SIZE)
{
    for (int i = 0; i <SIZE; ++i)
    {
        printf("%d ",a[i]);
    }
}
void sorting(int beg, int end)
{
    if (beg < end)
    {
        int p = partition(beg, end);
        if(vfork()==0)
        {
            sorting(beg, p - 1);
            exit(0);
        }
        else
        {
            sorting(p + 1, end);
        }
    }
}
int main(){
    reads(SIZE);
    //print(SIZE);
    printf("\n\n");
    sorting(0,SIZE-1);
    print(SIZE);
    printf("\n");
}
