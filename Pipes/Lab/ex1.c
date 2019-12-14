#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
	//------------Test Drive Pipes----------
    char w[20]="String!";
    char r[20];
    int fd[2];
    pipe(fd);
    if(fork()>0)
    {
        close(fd[0]);
        write(fd[1],w,strlen(w)+1);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        read(fd[0],r,20);
        printf("%s\n",r);
        close(fd[0]);
    }
    return 0;
}
