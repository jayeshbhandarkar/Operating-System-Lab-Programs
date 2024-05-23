// Paging Technique of Memory Management

#include <stdio.h>

struct pstruct 
{
  int fno;
  int pbit;
} ptable[10];

int pmsize, lmsize, psize, frame, page, ftable[20], frameno;

void info() 
{
  printf("\n MEMORY MANAGEMENT USING PAGING \n");
  printf("\n Enter the Size of Physical Memory: ");
  scanf("%d", &pmsize);
  printf("\n Enter the Size of Logical Memory: ");
  scanf("%d", &lmsize);
  printf("\n Enter the Partition Size: ");
  scanf("%d", &psize);
  frame = (int)pmsize / psize;
  page = (int)lmsize / psize;
  printf("\n The Physical Memory is Divided into %d No.of Frames \n", frame);
  printf("\n The Logical Memory is Divided into %d No.of Pages \n", page);
}

void assign() 
{
  int i;
  for (i = 0; i < page; i++) 
  {
    ptable[i].fno = -1;
    ptable[i].pbit = -1;
  }

  for (i = 0; i < frame; i++)
    ftable[i] = 32555;

  for (i = 0; i < page; i++) 
  {
    printf("\n Enter the Frame Number Where Page %d must be placed: ", i);
    scanf("%d", &frameno);
    ftable[frameno] = i;
    if (ptable[i].pbit == -1) 
    {
      ptable[i].fno = frameno;
      ptable[i].pbit = 1;
    }
  }

  printf("\n\n PAGE TABLE \n\n");
  printf("Page_Address  Frame_No.  Presence_Bit \n\n");

  for (i = 0; i < page; i++)
    printf("%d\t\t%d\t\t%d\n", i, ptable[i].fno, ptable[i].pbit);
  printf("\n\n FRAME TABLE \n\n");
  printf("Frame_Address  Page_No \n\n");

  for (i = 0; i < frame; i++)
    printf("%d\t\t%d\n", i, ftable[i]);
}

void cphyaddr() 
{
  int laddr, paddr, disp, phyaddr, baddr;

  // clrscr();
  printf("\n\n Process to create the Physical Address \n\n");
  printf("\n Enter the Base Address: ");
  scanf("%d", &baddr);
  printf("\n Enter the Logical Address: ");
  scanf("%d", &laddr);
  paddr = laddr / psize;
  disp = laddr % psize;
  if (ptable[paddr].pbit == 1)
    phyaddr = baddr + (ptable[paddr].fno * psize) + disp;
  printf("\n The Physical Address where the instruction present: %d", phyaddr);
}

int main() 
{
  info();
  assign();
  cphyaddr();
}


/*  **** OUTPUT ****
MEMORY MANAGEMENT USING PAGING 

Enter the Size of Physical Memory: 16

Enter the Size of Logical Memory: 8

Enter the Partition Size: 2

The Physical Memory is Divided into 8 No.of Frames 

The Logical Memory is Divided into 4 No.of Pages 

Enter the Frame Number Where Page 0 must be placed: 5

Enter the Frame Number Where Page 1 must be placed: 6

Enter the Frame Number Where Page 2 must be placed: 7

Enter the Frame Number Where Page 3 must be placed: 2

 PAGE TABLE 

Page_Address   Frame_No.   Presence_Bit 

0               5               1
1               6               1
2               7               1
3               2               1


 FRAME TABLE 

Frame_Address   Page_No 

0               32555
1               32555
2               3
3               32555
4               32555
5               0
6               1
7               2

Process to create the Physical Address 

Enter the Base Address: 1000

Enter the Logical Address: 3

The Physical Address where the instruction present: 1013
*/