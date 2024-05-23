// DeadLock Avoidance

#include <stdio.h>

int main() 
{
  int r[1][10], av[1][10];
  int all[10][10], max[10][10], ne[10][10], w[10], safe[10];
  int i = 0, j = 0, k = 0, l = 0, np = 0, nr = 0, count = 0, cnt = 0;
  
  printf("Enter the number of processes in a system: ");
  scanf("%d", &np);
  printf("Enter the number of resources in a system: ");
  scanf("%d", &nr);

  for (i = 1; i <= nr; i++) 
  {
    printf("\n Enter the number of instances of resource R%d: ", i);
    scanf("%d", &r[0][i]);
    av[0][i] = r[0][i];
  }

  for (i = 1; i <= np; i++)
    for (j = 1; j <= nr; j++)
      all[i][j] = ne[i][j] = max[i][j] = w[i] = 0;

  printf("\n Enter the allocation matrix: ");
  for (i = 1; i <= np; i++) 
  {
    printf("\n");
    for (j = 1; j <= nr; j++) 
    {
      scanf("%d", &all[i][j]);
      av[0][j] = av[0][j] - all[i][j];
    }
  }

  printf("\n Enter the maximum matrix: ");
  for (i = 1; i <= np; i++) 
  {
    printf("\n");
    for (j = 1; j <= nr; j++) 
    {
      scanf("%d", &max[i][j]);
    }
  }

  for (i = 1; i <= np; i++) 
  {
    for (j = 1; j <= nr; j++) 
    {
      ne[i][j] = max[i][j] - all[i][j];
    }
  }

  for (i = 1; i <= np; i++)
  {
    printf("\n Process P%d:", i);
    for (j = 1; j <= nr; j++) 
    {
      printf("\n Allocated: %d\t", all[i][j]);
      printf("Maximum: %d\t", max[i][j]);
      printf("Need: %d\t", ne[i][j]);
    }
    printf("\n\n");
  }
  printf("\n Availability: ");
  for (i = 1; i <= nr; i++)
    printf("R%d %d\t", i, av[0][i]);

  printf("\n ");
  printf("\n Safe sequence");

  for (count = 1; count <= np; count++) 
  {
    for (i = 1; i <= np; i++) 
    {
      cnt = 0;
      for (j = 1; j <= nr; j++) 
      {
        if (ne[i][j] <= av[0][j] && w[i] == 0)
          cnt++;
      }
      if (cnt == nr) 
      {
        k++;
        safe[k] = i;

        for (l = 1; l <= nr; l++)
          av[0][l] = av[0][l] + all[i][l];

        printf("\n P%d ", safe[k]);
        printf("\t Availability: ");

        for (l = 1; l <= nr; l++)
          printf("R%d %d\t", l, av[0][l]);
          
        w[i] = 1;
      }
    }
  }
}


/*  **** OUTPUT ****

Enter the number of processes in a system: 3
Enter the number of resources in a system: 3

Enter the number of instances of resource R1: 10

Enter the number of instances of resource R2: 5

Enter the number of instances of resource R3: 7

Enter the allocation matrix: 
0 1 0

2 0 0

3 0 2

Enter the maximum matrix: 
7 5 3

3 2 2

9 0 2

 Process P1:
 Allocated: 0   Maximum: 7      Need: 7
 Allocated: 1   Maximum: 5      Need: 4
 Allocated: 0   Maximum: 3      Need: 3


 Process P2:
 Allocated: 2   Maximum: 3      Need: 1
 Allocated: 0   Maximum: 2      Need: 2
 Allocated: 0   Maximum: 2      Need: 2


 Process P3:
 Allocated: 3   Maximum: 9      Need: 6
 Allocated: 0   Maximum: 0      Need: 0
 Allocated: 2   Maximum: 2      Need: 0


 Availability: R1 5     R2 4    R3 5
 
 Safe sequence
 P2      Availability: R1 7     R2 4    R3 5
 P3      Availability: R1 10    R2 4    R3 7
 P1      Availability: R1 10    R2 5    R3 7

*/
