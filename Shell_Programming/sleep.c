// sleep

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	int p;
	p=fork();
	if(p==0)
	{
 		printf("\n i am child process%d", getpid()); sleep(15);
 		printf("\n I am parent of child process%d",getpid());
 	}
 	else
 	{
 		printf("\n I am parent of child %d",getpid());
 		printf("\n I am parent's parent %d",getpid());
 	}
}
   
/*	**** OUTPUT ****

I am parent of child 4379
I am parent's parent 4379

*/