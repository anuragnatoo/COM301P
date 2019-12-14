#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
	printf("----------------------Palindrome Check-------------------\n");
    char w[20];
    printf("Enter input string:\n");
    scanf("%s",w);
    int x;
    char r[20],s[20];
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
        for(int i=0;i<strlen(r);i++)
            s[strlen(r)-i-1]=r[i];
        s[strlen(r)]='\0';
        x=strlen(r);
        printf("Reversed string:%s\n",s);
        //printf("%s\n",s);
        //printf("%s\n",r);
        if(strncmp(s,r,x)==0)
            printf("\nPalindrome\n");
        else 
            printf("\nNot palindrome\n");
        close(fd[0]);
    }
    
    return 0;
}

