// FIFO Page Replacement Algorithm

#include<stdio.h>

void fifo(int string[20],int n,int size)
{
    //Creating array for block storage
    int frames[n];
    //Initializing each block with -1
    for (int i=0;i<n;i++)
        frames[i]=-1;

    //Index to insert element
    int index=-1;

    //Counters
    int page_miss=0;
    int page_hits=0;

    //Traversing each symbol in fifo
    for (int i=0;i<size;i++)
    {
        int symbol=string[i];
        int flag=0;

        for(int j=0;j<n;j++)
        {
            if (symbol==frames[j])
            {
                flag=1;
                break;
            }
        }

        if (flag==1)
        {
            printf("\n Page-->: %d  Frame: ",symbol);
            for (int j=0;j<n;j++)
                printf("%d ",frames[j]);
            page_hits+=1;
        }
        else
        {
            index=(index+1)%n;
            frames[index]=symbol;
            page_miss+=1;
            printf("\n Page-->: %d  Frame: ",symbol);
            for (int j=0;j<n;j++)
                printf("%d ",frames[j]);
        }
    }
    printf("\n\n No of Page Hits are: %d",page_hits);
    printf("\n No of Page Faults are: %d",page_miss);
}

//Main function
int main(void)
{
    // int string[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int string[50],i,no_frames=3,size,n;
    printf("\n How many No of Pages? ");
    scanf("%d",&n);
    printf("\n Enter the Pages: ");
    for(i=0;i<n;i++)
        scanf("%d",&string[i]);
    fifo(string,no_frames,n);
    return 0;
}

/*  **** OUTPUT ****
How many No of Pages? 20

Enter the Pages: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1      

Page-->: 7  Frame: 7 -1 -1 
Page-->: 0  Frame: 7 0 -1 
Page-->: 1  Frame: 7 0 1 
Page-->: 2  Frame: 2 0 1 
Page-->: 0  Frame: 2 0 1 
Page-->: 3  Frame: 2 3 1 
Page-->: 0  Frame: 2 3 0 
Page-->: 4  Frame: 4 3 0 
Page-->: 2  Frame: 4 2 0 
Page-->: 3  Frame: 4 2 3 
Page-->: 0  Frame: 0 2 3 
Page-->: 3  Frame: 0 2 3 
Page-->: 2  Frame: 0 2 3 
Page-->: 1  Frame: 0 1 3 
Page-->: 2  Frame: 0 1 2 
Page-->: 0  Frame: 0 1 2 
Page-->: 1  Frame: 0 1 2 
Page-->: 7  Frame: 7 1 2 
Page-->: 0  Frame: 7 0 2 
Page-->: 1  Frame: 7 0 1 

No of Page Hits are: 5
No of Page Faults are: 15

*/
