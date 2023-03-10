#include "sort.h"
void read(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
}

void print(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void insertion_sort(int a[], int n)
{ //ter elmentiig bairand n ortol jishne
	/***************************************************
	 * Даалгавар: Энэ хэсэгт өөрийн insertion sort-ийг
	 * хийх кодыг бичнэ.
	 * a     нь эрэмбэлэх хүснэгт
	 * n     нь хүснэгтэд байгаа утгуудын тоо
	 ***************************************************/
	for(int i=1; i < n ; i++){
		// 99 1 1 4 5 99  //
		// 0  1 2 3 4 5
		int key = a[i] ;
		int j = i - 1 ;
		// hoishih uildeld swap hiih
		while(key < a[j] && j >= 0){
			a[j + 1] = a[j] ;
			j-- ;
		}
		// jishigdej baigaadaa utgaa olgono
		a[j + 1] = key ;
	}
	
}		

void selection_sort(int a[], int n)
{
	/***************************************************
	 * Даалгавар: Энэ хэсэгт өөрийн selection sort-ийг
	 * хийх кодыг бичнэ.	
	 * a     нь эрэмбэлэх хүснэгт
	 * n     нь хүснэгтэд байгаа утгуудын тоо
	 ***************************************************/
	int  temp ;
	for(int j=0; j<n; j++){
		int min=j;
		for(int i=j+1; i<n; i++){
			// j hooshihoos hamgiin baga olno 
			if(a[i] < a[min]){
				min=i;
			}
		}
		// hamgiin bag
		if(min != j){
			temp = a[min];
			a[min] = a[j];
			a[j] = temp;
		}
	}

}

void bubble_sort(int a[], int n)
{
	/***************************************************
	 * Даалгавар: Энэ хэсэгт өөрийн bubble sort-ийг
	 * хийх кодыг бичнэ.
	 * a     нь эрэмбэлэх хүснэгт
	 * n     нь хүснэгтэд байгаа утгуудын тоо		
	 ***************************************************/

	int temp;
	for (int i = 0 ; i < n - 1; i++)
    {
		// hamgiin ihiig hoino n garagj baiga uchir
    	for (int j = 0 ; j < n - i - 1; j++)
    	{
      		if (a[j] > a[j+1]) /* j j+1 elementiig toirog maygaar solino*/
      		{
       		temp   = a[j];
       		a[j]   = a[j+1];
        	a[j+1] = temp;
      		}
   		}
  	}
}
