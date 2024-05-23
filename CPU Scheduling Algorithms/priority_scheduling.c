#include<stdio.h>

void main()
{
	int i,j,pno[10],prior[10],bt[10],n,wt[10],tt[10],w1=0,t1=0,s;
	float aw,at;
	
	printf("enter the number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("The process %d:\n",i+1);
		printf("Enter the burst time of processes:");
		scanf("%d",&bt[i]);
		printf("Enter the priority of processes %d:",i+1);
		scanf("%d",&prior[i]);
		pno[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(prior[i]<prior[j])
			{
				s=prior[i];
				prior[i]=prior[j];
				prior[j]=s;
				s=bt[i]; 
				bt[i]=bt[j];
				bt[j]=s;
				s=pno[i];
				pno[i]=pno[j];
				pno[j]=s;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{ 
		wt[0]=0;
		tt[0]=bt[0];
		wt[i+1]=bt[i]+wt[i];
		tt[i+1]=tt[i]+bt[i+1];
		w1=w1+wt[i];
		t1=t1+tt[i];
		aw=w1/n;
		at=t1/n;
	}
	printf(" \n job \t bt \t wt \t tat \t prior\n");
	
	for(i=0;i<n;i++)
		printf("%d \t %d \t %d\t %d\t %d\n",pno[i],bt[i],wt[i],tt[i],prior[i]);
		printf("aw=%f \t at=%f \n",aw,at);
}


/*	**** OUTPUT ****

enter the number of processes:3
The process 1:
Enter the burst time of processes:12
Enter the priority of processes 1:2
The process 2:
Enter the burst time of processes:15
Enter the priority of processes 2:1
The process 3:
Enter the burst time of processes:2
Enter the priority of processes 3:3
 
 job     bt      wt      tat     prior
2        15      0       15      1
1        12      15      27      2
3        2       27      29      3
aw=14.000000     at=23.000000

*/