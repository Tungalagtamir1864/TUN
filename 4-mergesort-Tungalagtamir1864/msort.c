#include "sort.h"
#define CUTOFF 10

int nereer(const Student *a, const Student *b)
{
        if (strcmp(a->name, b->name) <0){
          return 1 ;
        }
        else if (strcmp(a->name, b->name) == 0){
          return 0;
        } 
        else {
          return -1 ;
        }
}

int nasaar(const Student *a, const Student *b)
{
        /* функцийг гүйцээ */
        if (a->age < b->age){
          return 1 ;
        }
        else if (a->age == b->age){
          return 0;
        }
        else {
          return -1 ;
        }
}

int golchoor(const Student *a, const Student *b)
{
        /* функцийг гүйцээ */
        if (a->gpa < b->gpa){
          return 1 ;
        }
        else if (a->gpa == b->gpa){
          return 0;
        }
        else {
          return -1 ;
        }
	
}

void insertion_sort(Student a[],
                    int lo, int hi,
                    int (*less)
                    (const Student *, const Student *))
{
        /* функцийг гүйцээ */	
        // lo hi hurtel ermbelene less zaagch
        Student tmp ;
        int i;
        for( i=lo ; i<=hi; i++){
          int j = i ;
          while (less(a + j - 1, a + j) < 0 && j > lo){
            tmp = a[j - 1] ;
            a[j - 1] = a[j] ;
            a[j] = tmp ;
            j = j - 1 ;
          }
        }
}

void merge(Student a[],
           Student aux[],
           int lo,
           int mid,
           int hi,
           int (*less)(const Student *, const Student *)){
        int k, i, j ;
        for(k = lo ; k <= hi; k++){
          aux[k] = a[k];
        }

        i = lo ; //ehlel
        j = mid + 1 ;  // 2 dahi 
/*6 too
1 2 3 4 5 6 7
i>mid
1++ > 4*/
      for(k = lo; k <= hi; k++){
        if (i > mid){ // ehnii  duurtsen uchir  2 dundaas n ehleed hiine
          a[k] = aux[j++] ;                        
          }
          else if (j > hi){ // 2 dahi husnegt duurtsen  
            a[k] = aux[i++] ;
          }
          else if (less(&aux[j], &aux[i]) > 0){  
            a[k] = aux[j++] ; 
          }
          else {
            a[k] = aux[i++] ;
          }
        }
}

void mergesort(Student a[],
               Student aux[],
               int lo,
               int hi,
               int (*less)(const Student *, const Student *))
{
        /* функцийг гүйцээ */

        if (hi - lo <= CUTOFF){
          insertion_sort(a, lo, hi, less) ;
          return ;
        }
        int mid ;
        mid = lo + (hi - lo) / 2 ; 
        mergesort(a, aux, lo, mid, less); 
        mergesort(a, aux, mid + 1, hi, less);
        merge(a, aux, lo, mid, hi, less);    

}
