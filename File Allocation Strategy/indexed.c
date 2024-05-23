#include <stdio.h>

int main() 
{
    int n, m[20], i, j, ib[20], b[20][20];
    printf("Enter no. of files:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("Enter index block for file %d:", i + 1);
        scanf("%d", &ib[i]);
        printf("Enter blocks occupied by file %d:", i + 1);
        scanf("%d", &m[i]);
        printf("Enter blocks of file %d:", i + 1);
        for (j = 0; j < m[i]; j++)
            scanf("%d", &b[i][j]);
    }

    printf("\nFile\tIndex\tLength\n");

    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, ib[i], m[i]);

    printf("Blocks occupied are:\n");

    for (i = 0; i < n; i++)
    {
        printf("File No %d \n", i + 1);

        for (j = 0; j < m[i]; j++)
            printf("\t%d--->%d\n", ib[i], b[i][j]);

        printf("\n");
    }
    
    return 0;
}


/*  **** OUTPUT ****

Enter no. of files:2
Enter index block for file 1:3
Enter blocks occupied by file 1:4
Enter blocks of file 1:9 4 6 7
Enter index block for file 2:5
Enter blocks occupied by file 2:2
Enter blocks of file 2:10 8

File    Index   Length
1       3       4
2       5       2
Blocks occupied are:
File No 1 
        3--->9
        3--->4
        3--->6
        3--->7

File No 2 
        5--->10
        5--->8

*/