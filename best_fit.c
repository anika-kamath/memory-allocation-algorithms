#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int main() {
    int blockSize[MAX], processSize[MAX], bestFit[MAX], fragment[MAX];
    int bSize, pSize, i, j, totalFragment = 0, allocated = 0;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &bSize);

    printf("Enter the size of each memory block:\n");
    for (i = 0; i < bSize; i++) {
        printf("Block %d: ", i+1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &pSize);

    printf("Enter the size of each process:\n");
    for (i = 0; i < pSize; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &processSize[i]);
    }

    // Find the best fit for each process
    for (i = 0; i < pSize; i++) {
        int min = -1;
        for (j = 0; j < bSize; j++) {
            if (processSize[i] <= blockSize[j]) {
                if (min == -1) {
                    min = j;
                } else if (blockSize[j] < blockSize[min]) {
                    min = j;
                }
            }
        }

        if (min != -1) {
            bestFit[i] = min;
            fragment[i] = blockSize[min] - processSize[i];
            blockSize[min] -= processSize[i];
            allocated++;
        } else {
            bestFit[i] = -1;
            fragment[i] = -1;
        }
    }

    // Calculate external fragmentation
    for (i = 0; i < bSize; i++) {
        totalFragment += blockSize[i];
    }

    // Print allocation details
    printf("\nProcess No.\tProcess Size\tBlock No.\tFragmentation\n");
    for (i = 0; i < pSize; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (bestFit[i] != -1) {
            printf("%d\t\t%d\n", bestFit[i]+1, fragment[i]);
        } else {
            printf("Not Allocated\t-\n");
        }
    }

    // Print external fragmentation
    if (allocated == pSize) {
        printf("\nTotal External Fragmentation: %d\n", totalFragment);
    } else {
        printf("\nExternal Fragmentation Occurred: Not all processes could be allocated.\n");
    }

    return 0;
}
