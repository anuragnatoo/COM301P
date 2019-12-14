#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main() 
{ 
	printf("--------------Concatenation-----------------\n");
	int fd1[2]; // Used to store two ends of first pipe 
	int fd2[2]; // Used to store two ends of second pip
    pipe(fd1);
    pipe(fd2); 
	char fixed_str[] = "Concatenated"; 
	char input_str[100]; 
	pid_t p; 
	printf("Enter input string\n");
	scanf("%s", input_str); 
	p = fork(); 
	if (p > 0) 
	{ 
		char concat_str[100]; 
		close(fd1[0]); // Close reading end of first pipe 
		write(fd1[1], input_str, strlen(input_str)+1); 
		close(fd1[1]); 
		wait(NULL); 
		close(fd2[1]); // Close writing end of second pipe 
		read(fd2[0], concat_str, 100); 
		printf("Concatenated string %s\n", concat_str); 
		close(fd2[0]); 
	} 

	else
	{ 
		close(fd1[1]); // Close writing end of first pipe 
		char concat_str[100]; 
		read(fd1[0], concat_str, 100); 
		int k = strlen(concat_str); 
		int i; 
		for (i=0; i<strlen(fixed_str); i++) 
			concat_str[k++] = fixed_str[i]; 
		concat_str[k] = '\0'; // string ends with '\0' 
		close(fd1[0]); 
		close(fd2[0]); 
		write(fd2[1], concat_str, strlen(concat_str)+1); 
		close(fd2[1]); 
		exit(0); 
	} 
} 
