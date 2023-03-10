#include "sort.h"
int A[1000];
int main()
{       
        printf("insertion sort heden too oruulah ve: ");
        int n;
        scanf("%d", &n);
        printf("insertion sort");
        read(A, n);
        insertion_sort(A, n);
        print(A, n);

        
        printf("selection sort heden too oruulah ve");
        scanf("%d", &n);
        read(A, n);
        selection_sort(A, n);
        print(A, n);

        printf("bubble sort heden too oruulah ve ");
        scanf("%d", &n);
        read(A, n);
        bubble_sort(A, n);
        print(A, n);        
        return 0;
}
