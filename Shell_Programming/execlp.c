// Execlp()

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	printf("Executing execlp()...\n");
	
	pid = fork();
	
	if(pid==-1)
 	{
 		perror("fork");
    	return 1;
 	}
 	else if(pid==0)
 	{	
  		execlp("ls", "ls", "-l", NULL);
  		perror("excelp");
  		exit(1);
 	}
 	else 
 	{
    	wait(NULL);
    	printf("Child process finished. \n");
 	}		
 	return 0;
}


/*	**** OUTPUT ****

Executing execlp()...
total 20
-rwxr-xr-x 1 runner18 runner18 16168 May 23 07:24 a.out
-rwxrwxrwx 1 root     root       450 May 23 07:24 main.c
Child process finished. 

*/