// Shared Memory and Inter Process Communication

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>

int main() 
{
  int shmid;
  key_t key = 0 * 10;
  shmid = shmget(key, 100, IPC_CREAT | 0666);

  if (shmid < 0)
    printf("\nfirst SHMID failed\n");
  else
    printf("\n first SHMID succeded id=%d\n", shmid);
  shmid = shmget(key, 101, IPC_CREAT | 0666);

  if (shmid < 0)
    printf("\nsecond SHMID failed\n");
  else
    printf("\n secondt SHMID succeded id=%d\n", shmid);
  shmid = shmget(key, 90, IPC_CREAT | 0666);

  if (shmid < 0)
    printf("\nthird SHMID failed\n");
  else
    printf("\n third SHMID succeded id=%d\n", shmid);
}


/*  **** OUTPUT ****
first SHMID succeded id=0

secondt SHMID succeded id=1

third SHMID succeded id=2
*/