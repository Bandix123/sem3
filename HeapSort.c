#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b); // перестановка
void siftDown(int* heap, int i, int n); // просеивание вниз
void heapSort(int* arr, int n); // пирамидальная сортировка
void printArray(int* arr, int n); // вывод массива

int main(void) {
    srand(time(NULL));

    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);

    int* array = (int*) malloc(n * sizeof(int));
    if(array == NULL){
        printf("No memory, end of program\n");
        exit(1);
    }

    for(int i = 0; i < n; ++i) // заполнение массива случайными числами
        array[i] = rand();

    // вывод исходного массива
    printf("Initial array: ");
    printArray(array, n);

    double start = clock();
    // сортировка массива
    heapSort(array, n);

    // вывод отсортированного массива
    printf("Sorted array: ");
    printArray(array, n);

    // вывод времени работы сортировки
    double finish = (clock() - start) / CLOCKS_PER_SEC;
    printf("Time: %f", finish);

    free(array);

    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(int* heap, int i, int n){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);

        siftDown(heap, largest, n);
    }
}

void heapSort(int* arr, int n){
    // построение пирамиды из массива
    for(int i = n/2 - 1; i >= 0; --i)
        siftDown(arr, i, n);

    for(int i = n-1; i > 0; --i){
        swap(&arr[0], &arr[i]);

        siftDown(arr, 0, i);
    }
}

void printArray(int* arr, int n){
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
