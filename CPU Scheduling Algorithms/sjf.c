// Shortest Job First Scheduling

#include<stdio.h>

int main()
{
	int bt[20],p,wt=0,tat,i,j,twt=0,ttat=0,temp;
	printf("Enter the no.of process:");
	scanf("%d",&p);
	printf("Enter the no.of burst time for each process:");

	for(i=0;i<p;i++)
	{
		scanf("\n%d",&bt[i]);
	}
	
	for(i=0; i<p; i++)
	{
		for(j=i+1;j<p;j++)
		{
			if(bt[i]>bt[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
			}
		}
	}
	printf("Burst time \t\t Waiting time \t\t Turn-round time");

	for(i=0;i<p;i++)	
	{
		twt=twt+wt; tat=bt[i]+wt;
		ttat=ttat+tat;
		printf("\n %d \t\t\t %d \t\t\t %d",bt[i],wt,tat);
		wt=wt+bt[i];
	}

	printf("\n\n Average waiting time :%d",twt/p);
	printf("\n\n Average turn around time :%d",ttat/p);
}


/*	**** OUTPUT ****

Enter the no.of process:3
Enter the no.of burst time for each process:8 2 4
Burst time               Waiting time            Turn-round time
 2                       0                       2
 4                       2                       6
 8                       6                       14

Average waiting time :2

Average turn around time :7

*/