#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
        /* Энд оруулах үйлдлийг хийнэ үү */
        Elm *elm = malloc(sizeof(Elm)) ;
        elm->x = x ;
        elm->next = p->top ;
        p->top = elm ;
        p->len++; 
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
        /* Энд гаргах үйлдлийг хийнэ үү */
        struct Elm *elm = p->top ;
        p->top = elm->next ;
        p->len-- ;
}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p)
{
        /* Энд хэвлэх үйлдлийг хийнэ үү */
        // Elm *elm = malloc(sizeof(Elm)) ;
        Elm *elm = p->top ;
        while (elm != NULL){
                printf("%d", elm->x) ;
                elm = elm->next ;
        }
}
