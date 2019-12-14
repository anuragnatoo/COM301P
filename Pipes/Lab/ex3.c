#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char *args[2]={"ls",NULL};
    int nb;
    char buf[20];
    int fd[2];
    pipe(fd);
    if(fork()>0)
    {
        close(fd[0]);
        dup2(fd[1],1);
        execvp("ls",args);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        while ((nb=read(fd[0],buf,20))>0)
        {
            for(int i=0;i<nb;i++)
            {
                buf[i]=toupper(buf[i]);
                printf("%c",buf[i]);
            }
            printf("\n");
        }
        
        close(fd[0]);
    } 
    return 0;
}
