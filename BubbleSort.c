#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *num, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (num[j - 1] > num[j])
            {
                int temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}
int main(void)
{
    int* a;
    int n;
    printf("Enter size of massive:");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d ", a[i]);
    }
    clock_t start = clock();
    bubbleSort(a, n);
    start = clock() - start;
    printf("\n");
    for (int i = 0; i<n; i++)
        printf("%d ", a[i]);
    printf("\nsorting time %.5f\n", (double)start/CLOCKS_PER_SEC);

    free(a);
    return 0;
}
