#include <stdio.h>

int main() {
    int n, i, j, b[20], sb[20], t[20], x, c[20][20];
    printf("Enter no. of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("Enter no. of blocks occupied by file %d: ", i + 1);
        scanf("%d", &b[i]); 
        printf("Enter the starting block of file %d: ", i + 1);
        scanf("%d", &sb[i]); 
        t[i] = sb[i];
        
        for (j = 0; j < b[i]; j++) 
        {
            c[i][j] = sb[i]++;
        }
    }

    printf("Filename Start blockLength \n");

    for (i = 0; i < n; i++) 
    {
        printf("%d\t\t %d \t\t\t%d\n", i + 1, t[i], b[i]);
    }

    printf("Blocks occupied are:\n");

    for (i = 0; i < n; i++) 
    {
        printf("File no %d: ", i + 1);
        for (j = 0; j < b[i]; j++) 
        {
            printf("\t%d", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*  **** OUTPUT ****

Enter no. of files:2
Enter no. of blocks occupied by file 1: 3
Enter the starting block of file 1: 4
Enter no. of blocks occupied by file 2: 2
Enter the starting block of file 2: 8
Filename Start blockLength 
1                4                      3
2                8                      2
Blocks occupied are:
File no 1:      4       5       6
File no 2:      8       9

*/