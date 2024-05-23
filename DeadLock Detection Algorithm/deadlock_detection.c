// DeadLock Detection

#include <stdio.h>

int main() 
{
  int found, flag, l, p[10][10], tp, tr, c[10][10];
  int i, j, k = 1, m[10], r[10], a[10], temp[10], sum = 0;

  printf("\n Enter total no of processes: ");
  scanf("%d", &tp);
  
  printf("\n Enter total no of resources: ");
  scanf("%d", &tr);
  
  printf("\n Enter claim (Max. Need) matrix\n");
  for (i = 1; i <= tp; i++) 
  {
    printf("\n Process %d:\n", i);
    for (j = 1; j <= tr; j++)
        scanf("%d", &c[i][j]);
  }

  printf("\n Enter allocation matrix\n");
  for (i = 1; i <= tp; i++) 
  {
    printf("\n Process %d:\n", i);
    for (j = 1; j <= tr; j++)
        scanf("%d", &p[i][j]);
  }

  printf("\n Enter resource vector (Total resources):\n");
  for (i = 1; i <= tr; i++)
    scanf("%d", &r[i]);

  printf("\n Enter availability vector (available resources):\n");
  for (i = 1; i <= tr; i++) 
  {
    scanf("%d", &a[i]);
    temp[i] = a[i];
  }

  for (i = 1; i <= tp; i++) 
  {
    sum = 0;
    for (j = 1; j <= tr; j++)
      sum += p[i][j];

    if (sum == 0) 
    {
      m[k] = i;
      k++;
    }
  }

  for (i = 1; i <= tp; i++) 
  {
    for (l = 1; l < k; l++)
      if (i != m[l]) 
      {
        flag = 1;
        for (j = 1; j <= tr; j++)
          if (c[i][j] < temp[j]) 
          {
            flag = 0;
            break;
          }
      }

    if (flag == 1) 
    {
      m[k] = i;
      k++;
      for (j = 1; j <= tr; j++)
        temp[j] += p[i][j];
    }
  }

  printf("\n Deadlock causing processes are: ");
  for (j = 1; j <= tp; j++) 
  {
    found = 0;
    for (i = 1; i < k; i++) 
    {
      if (j == m[i])
        found = 1;
    }
    
    if (found == 0)
      printf("%d\t", j);
  }
}


/*  **** OUTPUT ****

Enter total no of processes: 4
Enter total no of resources: 5
Enter claim (Max. Need) matrix
Process 1:
0 1 0 0 1
Process 2:
0 0 1 0 1
Process 3:
0 0 0 0 1
Process 4:
1 0 1 0 1
Enter allocation matrix
Process 1:
1 0 1 1 0
Process 2:
1 1 0 0 0  
Process 3:
0 0 0 1 0
Process 4:
0 0 0 0 0
Enter resource vector (Total resources):
2 1 1 2 1
Enter availability vector (available resources):
0 0 0 0 1
Deadlock causing processes are: 2     3
*/