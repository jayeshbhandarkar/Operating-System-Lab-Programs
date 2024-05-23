#include <stdio.h>
//#include <conio.h>
void main()
{
	int b[10],i,j=1,n,temp,burst[10],wait[10],turn[10],p[10],a=1,q,tat[10],t1=0;
	float t=0,w=0;
	
	printf("Enter the no of process & time quantum: ");
	scanf("%d%d",&n,&q);
	burst[0]=0; 
	b[0]=0;
	tat[0]=0;
	p[0]=0;
	printf("Enter burst time: ");
	
	for(i=1;i<=n;i++)
		scanf("%d",&burst[i]);
		
	for(i=1;i<=n;i++) 
		b[i]=burst[i];
		
	printf("\n\n\t\t Gantt chart: \n");
	printf("\n"); 
	
	for(i=1;i<=n;i++)
	{
		if(b[i]>0)
		{ 
			a=1;
			printf("P%d\t|",i);
			
			if(b[i]>=q)
			{
				t1=t1+q;
				p[j]=t1;
				j++;
			}
			else if(b[i]<q)
			{
				t1=t1+b[i];
				p[j]=t1;
				j++;
			}
			
			b[i]=b[i]-q;

			if(b[i]<=0)
				tat[i]=t1;
		}
		else 
			a++;

		if(a==n+1) 
			break;

		if(i==n)
			i=0;
	}
	printf("\n\n");
	
	for(i=0;i<j;i++)
		printf("%d\t",p[i]);

	for(i=1;i<=n;i++)
	{
		t=t+tat[i];
		w=w+tat[i]-burst[i];
	}
	w=w/n; 
	t=t/n;
	
	printf("\nThe average waiting time is %0.2f",w);
	printf("\nThe average turn around time is %0.2f",t);
	//getch();
}


/*	**** OUTPUT ****

Enter the no of process & time quantum: 3 5
Enter burst time: 10 5 3


                 Gantt chart: 

P1      |P2     |P3     |P1     |

0       5       10      13      18
The average waiting time is 7.67
The average turn around time is 13.67

*/