// Producer - Consumer Problem

#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=2,x=0;
int main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n 1.PRODUCER \n 2.CONSUMER \n 3.EXIT \n");

    while(1)
    {
        printf("\n ENTER YOUR CHOICE: ");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                if((mutex==1) && (empty!=0))
                    producer();
                else
                    printf("\n BUFFER IS FULL");
                break;

            case 2:
                if((mutex==1)&&(full!=0)) 
                    consumer();
                else
                    printf("\n BUFFER IS EMPTY");
                break;

            case 3:
                printf("\n Exit ....");
                exit(0);
                break;
        }
    }
}

int wait(int s)
{
    return(--s);
}

int signal(int s)
{
    return(++s);
}

void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\n Producer produces the item %d", x);
    mutex=signal(mutex);
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\n Consumer consumes item %d", x);
    x--;
    mutex=signal(mutex);
}

/*  **** OUTPUT ****

 1.PRODUCER 
 2.CONSUMER 
 3.EXIT 

 ENTER YOUR CHOICE: 1

 Producer produces the item 1
 ENTER YOUR CHOICE: 1

 Producer produces the item 2
 ENTER YOUR CHOICE: 1

 BUFFER IS FULL
 ENTER YOUR CHOICE: 2

 Consumer consumes item 2
 ENTER YOUR CHOICE: 2

 Consumer consumes item 1
 ENTER YOUR CHOICE: 2

 BUFFER IS EMPTY
 ENTER YOUR CHOICE: 3

 Exit ....

*/