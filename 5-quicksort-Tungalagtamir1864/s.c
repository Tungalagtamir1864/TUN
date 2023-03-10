 #include <stdio.h>

int main()
{
       // initially take p1 as first element
        int p1 = a[lo];
        // and p2 as last rightmost element
        int p2 = a[hi];
        int l = lo + 1;
        int g = hi - 1;
        int i = l;
        while (i <= g)
        { // i aas g dotorhiig shalgaad yvna

                if (a[i] < p1)
                { // ehnii elementees baga baival
                        swap(&a[i], &a[l]);
                        ++l;
                }
                else if (a[i] >= p2)
                {
                        while (a[g] > p2 && i < g)
                                --g;
                        swap(&a[i], &a[g]);
                        --g;
                        if (a[i] < p1)
                        {

                                swap(&a[i], &a[l]);
                                ++l;
                        }
                }
                ++i;
        }