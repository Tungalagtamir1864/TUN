#include "myinclude.h"

void read(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                scanf("%d", &A[i]);
}

void print(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                printf("%d ", A[i]);
        printf("\n");
}

int max(int A[], int n)
{
        int maxim = A[0] ;
        for(int i=0;i<n;i++){
                if (A[i] > maxim){
                        maxim = A[i] ;
                }
        }
        return maxim ;
}

int min(int A[], int n)
{
         
        int minim = A[0] ;
        for(int i=0;i<n;i++){
                if (A[i] < minim){
                        minim = A[i] ;
                }
        }
        return minim ;     
}

void copy(int A[], int n, int B[])
{
        for(int i=0; i < n; i++){
                B[i] = A[i] ;
        }       
}

int find(int A[], int n, int x)
{
        for(int i=0; i < n; i++){
                if (A[i] == x){
                        return i ;
                }
        }
        return -1 ;        
}

int make_set(int A[], int n, int B[])
{
        //A хүснэгтэд байгаа тоонуудын олонлогийг B хүснэгтэд хадгалаад, B хүснэгтэд хадгалсан олонлогийнхоо хэмжээг буцаана.
        int sz = 0, idx = 0;
        for(int i=0; i < n; i++){
                // ooroosoo omnoh elementtei temtsuug shalgah
                int bo = 1;
                for (int j = 0; j < i; j++){
                        if (A[i] == A[j]){
                                bo = 0;
                                break;
                        }
                }

                if (bo=1){
                        B[idx++] = A[i];
                        sz++;
                }
        }
        return sz ;   
}

int union_set(int A[], int n, int B[], int m)
{
       // A = {1, 5, 7}, B = {7, 5, 3, 7} бол A = {1, 5, 7, 3} болох ба 4-ыг буцаана.
        copy(A, n, B + m);
        return make_set(B, n + m, A);        
}

int intersection_set(int A[], int n, int B[], int m, int C[])
{
        int idx = 0;
        for(int i=0; i < n; i++){
                int bo = 0;

                for(int j = 0; j < m; j++){
                        if (A[i] == B[j]){
                                bo = 1;
                                break;
                        }
                }

                if (bo)
                {
                        C[idx++] = A[i];
                }
        }

        return idx;
}
