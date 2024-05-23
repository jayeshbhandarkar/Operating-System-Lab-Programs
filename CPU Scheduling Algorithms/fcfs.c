#include<stdio.h>

int main()
{
	int bt[20],p,wt=0,tat,i,twt=0,ttat=0;
	printf("Enter the no.of process:");
	scanf("%d",&p);
	printf("Enter the no.of burst time for each process:");
	for(i=0;i<p;i++)
	{
		scanf("\n%d",&bt[i]);
	}
	printf("Burst time \t\t Waiting time \t\t Turn-round time");

	for(i=0;i<p;i++)	
	{
		twt=twt+wt; 
		tat=bt[i]+wt;
		ttat=ttat+tat;
		printf("\n %d \t\t\t %d \t\t\t %d",bt[i],wt,tat);
		wt=wt+bt[i];
	}

	printf("\n\n Average waiting time :%d",twt/p);
	printf("\n\n Average turn around time :%d",ttat/p);
	return(0);
}


/*	**** OUTPUT ****

Enter the no.of process:3
Enter the no.of burst time for each process:5 10 15
Burst time               Waiting time            Turn-round time
 5                       0                       5
 10                      5                       15
 15                      15                      30

 Average waiting time :6

 Average turn around time :16
 
*/