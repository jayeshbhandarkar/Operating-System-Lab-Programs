// Optimal (LFU) Page Replacement Algorithm

#include <stdio.h>
int i, j, nof, nor, flag = 0, ref[50], frm[50], pf = 0, victim = -1;
int recent[10], optcal[50], count = 0;
int optvictim();
int main() 
{
  printf("\n Enter the No. of Frames: ");
  scanf("%d", &nof);
  printf("\n Enter the No.of Reference String: ");
  scanf("%d", &nor);
  printf("\n Enter the Reference String: ");
  
  for (i = 0; i < nor; i++)
    scanf("%d", &ref[i]);
  printf("\n The Given String: ");

  for (i = 0; i < nor; i++)
    printf("%4d", ref[i]);
  for (i = 0; i < nof; i++) 
  {
    frm[i] = -1;
    optcal[i] = 0;
  }

  for (i = 0; i < 10; i++)
    recent[i] = 0;
  printf("\n");

  for (i = 0; i < nor; i++) 
  {
    flag = 0;
    printf("\n Ref No. %d ->\t", ref[i]);

    for (j = 0; j < nof; j++) 
    {
      if (frm[j] == ref[i]) 
      {
        flag = 1;
        break;
      }
    }

    if (flag == 0) 
    {
      count++;
      if (count <= nof)
        victim++;
      else
        victim = optvictim(i);
      pf++;
      frm[victim] = ref[i];
      for (j = 0; j < nof; j++)
        printf("%4d", frm[j]);
    }
  }

  printf("\n Number of Page Faults: %d", pf);
}

int optvictim(int index) 
{
  int i, j, temp, notfound;
  for (i = 0; i < nof; i++) 
  {
    notfound = 1;
    for (j = index; j < nor; j++)
      if (frm[i] == ref[j]) 
      {
        notfound = 0;
        optcal[i] = j;
        break;
      }

    if (notfound == 1)
      return i;
  }

  temp = optcal[0];
  for (i = 1; i < nof; i++)
    if (temp < optcal[i])
      temp = optcal[i];

  for (i = 0; i < nof; i++)
    if (frm[temp] == frm[i])
      return i;

  return 0;
}


/*  **** OUTPUT ****

Enter the No. of Frames: 3
Enter the No.of Reference String: 6
Enter the Reference String: 6 5 4 2 3 1

The Given String:    6   5   4   2   3   1

Ref No. 6 ->      6  -1  -1
Ref No. 5 ->      6   5  -1
Ref No. 4 ->      6   5   4
Ref No. 2 ->      2   5   4
Ref No. 3 ->      3   5   4
Ref No. 1 ->      1   5   4
Number of Page Faults: 6
*/