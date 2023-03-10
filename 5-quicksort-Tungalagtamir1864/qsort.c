#include "my_qsort.h"
#ifndef CUTOFF
#define CUTOFF 10
#endif
static int init_seed = 0; // Random seed 1 удаа эхлүүлнэ
/*
  Оруулан эрэмбэлэх функц.
  [lo, hi] завсрах тоонуудыг оруулан эрэмбэлэх аргаар эрэмбэлнэ.
*/
static void insertion_sort(int a[], int lo, int hi)
{
        /* Оруулан эрэмбэлэх аргыг хэрэгжүүл */
        int tmp, i;

        for (i = lo + 1; i <= hi; i++)
        {
                tmp = a[i];
                int j = i - 1;
                while (j >= lo && a[j] > tmp)
                {
                        // swapping predeccessors to key element
                        a[j + 1] = a[j];
                        j = j - 1;
                }
                a[j + 1] = tmp;
        }
}

/*
  Хоёр утгыг хооронд солих функц
*/
static void swap(int *a, int *b)
{
        int tmp = *a;
        *a = *b;
        *b = tmp;
}

/*
  [lo, hi] завсрыг санамсаргүйгээр холих функц.
*/
static void random_shuffle(int a[], int lo, int hi)
{
        if (init_seed == 0)
        {
                srand(time(NULL));
                init_seed = 1;
        }
        int i, j;
        for (i = lo; i <= hi; i++)
        {
                j = rand() % (hi - lo) + lo;
                swap(&a[i], &a[j]);
        }
}

/*
  1-pivot хурдан эрэмбэлэх функц.
*/
static void _single_pivot_qsort(int a[], int lo, int hi)
{
        int piv = lo;
        int i = lo;
        int j = hi;
        // baga toon deer isnertion sort sain xD
        if (hi - lo <= CUTOFF)
        {
                insertion_sort(a, lo, hi);
        }
        if (lo >= hi)
        { // 1 elementtei esvel deed dood index ih
                return;
        }
        // pivot
        while (i < j)
        {
                // zuun talaas ih too haih
                while (i < hi && a[i] <= a[piv])
                {
                        i = i + 1;
                }
                // baruum talaas baga too haih
                while (a[j] > a[piv])
                {
                        j = j - 1;
                }
                // taarval bairiig ni solino.
                if (i < j)
                {
                        swap(&a[i], &a[j]);
                }
        }

        swap(&a[piv], &a[j]);
        _single_pivot_qsort(a, lo, j - 1);
        _single_pivot_qsort(a, j + 1, hi);
}

/*
  wrapper function for _single_pivot_qsort
  _single_pivot_qsort-ыг дуудахад ашиглах функц
 */
void single_pivot_qsort(int a[], int lo, int hi)
{
        random_shuffle(a, lo, hi);
        _single_pivot_qsort(a, lo, hi);
}

/*
  Dual-pivot хурдан эрэмбэлэх функц
*/
static void _dual_pivot_qsort(int a[], int lo, int hi)
{
        /*s
          Энд dual-pivot quicksort хэрэгжүүл
        */
        if (hi - lo <= CUTOFF)
        {
                insertion_sort(a, lo, hi);
        }
        if (lo >= hi)
        {
                return;
        }

        if (a[lo] > a[hi])
        {
                // herev 2 zahiin element iim baival
                // shuud swap hiine.
                swap(&a[lo], &a[hi]);
        }
        // initially take p1 as first element
        int p1 = a[lo];
        // and p2 as last rightmost element
        int p2 = a[hi];
        int l = lo + 1;
        int g = hi - 1;
        int i = l;

        while (i <= g)
        { // i aas g dotorhiig shalgaad yvna

                if (a[i] < p1) // ehnii elementees baga baival l ees urd baih ystoi
                {
                        swap(&a[i], &a[l]); // utgiig n soliod utga left tald nemegdej baigaa uchir neg deeshleh
                        ++l;
                }
                else if (a[i] >= p2) // 2 dagi elementees ih baival baival r aas hoino baih ystoi
                {
                        while (a[g] > p2 && i < g)
                                --g; // ih
                        swap(&a[i], &a[g]);
                        --g;
                }
                ++i;
        }
        --l; // daraagiin elementee shalgah geed nemtsen baigaa bolohoor --
        ++g;
        swap(&a[lo], &a[l]);
        swap(&a[hi], &a[g]);

        _dual_pivot_qsort(a, lo, l - 1);
        _dual_pivot_qsort(a, l + 1, g - 1);
        _dual_pivot_qsort(a, g + 1, hi);
}
/*
  wrapper function for _dual_pivot_qsort
  _dual_pivot_qsort-ыг дуудахад ашиглах функц
*/
void dual_pivot_qsort(int a[], int lo, int hi)
{
        random_shuffle(a, lo, hi);
        _dual_pivot_qsort(a, lo, hi);
}
