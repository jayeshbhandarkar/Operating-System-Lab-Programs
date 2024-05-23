// fork and getpid

#include<stdio.h>
#include<unistd.h>

int main()
{
   pid_t pid;
   printf("Before fork-Process ID: %d\n",getpid());
 
   pid=fork();
 
   if(pid==-1)
   {
      perror("fork");
      return 1;
   }
   else if(pid==0)
   {
  	   printf("After fork-childProcess ID:%d\n",getpid());
   }
   else 
   {
      printf("After fork-Prent process ID:%d\n",getpid());
   }
   return 0;
}


/* **** OUTPUT ****

Before fork-Process ID: 3767
After fork-Prent process ID:3767

*/