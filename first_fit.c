#include <stdio.h>
#define MAX 25

int main()
{
    int blockSize[MAX], processSize[MAX], firstFit[MAX];
    int bSize, pSize, i, j;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &bSize);

    printf("Enter the size of each memory block:\n");
    for (i = 0; i < bSize; i++)
    {
        printf("Block %d: ", i+1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &pSize);

    printf("Enter the size of each process:\n");
    for (i = 0; i < pSize; i++)
    {
        printf("Process %d: ", i+1);
        scanf("%d", &processSize[i]);
    }

    // Find the first fit for each process
    for (i = 0; i < pSize; i++)
    {
        for (j = 0; j < bSize; j++)
        {
            if (processSize[i] <= blockSize[j])
            {
                firstFit[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }

        if (j == bSize)
            firstFit[i] = -1;
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < pSize; i++)
    {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (firstFit[i] != -1)
            printf("%d\n", firstFit[i]+1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
