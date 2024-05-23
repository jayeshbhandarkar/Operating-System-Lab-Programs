//  Threading and Synchronization Applications

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

void *func(int n);
pthread_t philosopher[5];
pthread_mutex_t chopstick[5];

int main()
{
    int i,k; void *msg;
    for(i=1;i<=5;i++)
    {
        k=pthread_mutex_init(&chopstick[i],NULL); 
        if(k==-1)
        {
            printf("\n Mutex initialization failed \n");
            exit(1);
        }
    }
    
    for(i=1;i<=5;i++)
    {
        k=pthread_create(&philosopher[i],NULL,(void *)func,(int *)i);
        if(k!=0)
        {
            printf("\n Thread creation error \n");
            exit(1);
        }
    }

    for(i=1;i<=5;i++)
    {
        k=pthread_join(philosopher[i],&msg); 
        if(k!=0)
        {
            printf("\n Thread join failed \n"); 
            exit(1);
        }
    }

    for(i=1;i<=5;i++)
    {
        k=pthread_mutex_destroy(&chopstick[i]); 
        if(k!=0)
        {
            printf("\n Mutex Destroyed \n"); 
            exit(1);
        }
    }
    return 0;
}

void *func(int n)
{
    printf("\n Philosopher %d is thinking", n);
    pthread_mutex_lock(&chopstick[n]);          // when philosopher 5 is eating he takes fork 1 and fork 5
    pthread_mutex_lock(&chopstick[(n+1)%5]); 
    printf("\n Philosopher %d is eating", n); 
    sleep(3); 
    pthread_mutex_unlock(&chopstick[n]); 
    pthread_mutex_unlock(&chopstick[(n+1)%5]); 
    printf("\n Philosopher %d Finished eating", n);
}


/*  **** OUTPUT ****

 Philosopher 1 is thinking
 Philosopher 1 is eating
 Philosopher 2 is thinking
 Philosopher 4 is thinking
 Philosopher 4 is eating
 Philosopher 3 is thinking
 Philosopher 5 is thinking
 Philosopher 1 Finished eating
 Philosopher 4 Finished eating
 Philosopher 5 is eating
 Philosopher 3 is eating
 Philosopher 5 Finished eating
 Philosopher 3 Finished eating
 Philosopher 2 is eating
 Philosopher 2 Finished eating
 
*/