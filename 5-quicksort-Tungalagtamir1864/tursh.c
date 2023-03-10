#include <stdio.h>
static void insertion_sort(int a[], int lo, int hi)
{
    int tmp, i;
    for (i = lo + 1; i <= hi; i++)
    {
        printf("_________________");
        printf("i =  %d \n a[i] = %d \n ", i, a[i]);
        tmp = a[i];
        int j = i - 1;
        printf("j >= lo && a[j] > tmp--(%d >= %d && %d > %d)\n ", j, lo, a[j], tmp);
        while (j >= lo && a[j] > tmp)
        {
            printf("++++++++open++++++++");
            printf("a[j] =  %d \n", a[j]);
            printf("j =  %d \n", j);
            a[j + 1] = a[j];
            printf("a[j+1] =  %d \n", a[j + 1]);
            j = j - 1;
            printf("++++close++++++");
        }
        a[j + 1] = tmp;
        printf("suul -%d- a[j+1] =  %d \n", j, tmp);
    }
}

int main()
{
    int i, n = 4;
    int a[n] = {9, 6, 3, 7, 2};
    printf("/n ");
    for (i = 0; i < 5; i++)
        printf(" %d ", a[i]);
    printf("/n ");
    insertion_sort(a, 0, n);
    printf("/n");
    for (i = 0; i < 5; i++)
        printf(" %d ", a[i]);
    return 0;
}
/*
#include <math.h>
#include <stdio.h>


void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		 Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position 
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Driver program to test insertion sort 
int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
*/