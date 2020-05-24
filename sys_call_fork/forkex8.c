#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<wait.h>
void history(char his[],char cmd[])
{
    strcat(his,"\n");
    strcat(his,cmd);
}
int main()
{
    char his[1000]="";
    char cmd[100]={0};
    int top=0;
    while(1)
    {
        printf("%s","\nanuragnatoo@anurag-Lenovo-ideapad-310-sk~$" );
        scanf("%[^\n]%*c", cmd);
        history(his,cmd);
        if(strcmp(cmd,"quit")==0)
		{
			break;
		}
        char arg[10][100]={0};
        int argc=0,count=0;
        for(int i=0;i<strlen(cmd);i++)
        {
            if(cmd[i]==' ')
            {
                argc++;
                count=0;
            }
            else
            {
                arg[argc][count++]=cmd[i];
            }
        }
        char *argv[10]={0};
        int k=0;
        for(k=0;k<=argc;k++)
        {
            argv[k]=arg[k];
        }
        argv[k]=NULL;
        // printf("%s\n",".." );
        // for(int i=0;i<=argc;i++)
        //     printf("%s\n",arg[i] );

        int pid=fork();

        if(pid==0)
        {
            if(!strcmp(cmd,"history"))
            {
                printf("%s\n",his );
            }
            else
            {
                if(execvp(*argv,argv)<0)
                {
                    printf("%s\n","No such cmd found!\n" );
                }

            }
            exit(0);
        }
        else
            wait(NULL);
		

    }
}
