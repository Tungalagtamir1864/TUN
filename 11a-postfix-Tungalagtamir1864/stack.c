#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
        /* Энд оруулах үйлдлийг хийнэ үү */
        Elm *elm = malloc(sizeof(Elm)) ;
        elm->x = x ;
        // stackiin hamgiin ehnii element boloh bolohoor
        // p husnegtiin buh element dooshoo 1 yavna.
        elm->next = p->top ;
        // odoo hamgiin deed taliin element elm bolno
        p->top = elm ;
        // stack-d 1 element nemegdsen uchraas 
        // urt ni 1 eer nemegdene.
        p->len++ ;     
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
        /* Энд гаргах үйлдлийг хийнэ үү */
        Elm *elm = p->top ;
        // hamgiin deed taliin elementiin haygiig daraagiin 
        // elementiin haygaar soliod
        // hemjeeg ni 1 eer bagasgana
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
        Elm *elm = p->top ;
        // Stackiin buh elementeer 
        // iterate hiij bainaa
        while (elm != NULL){
                printf("%d", elm->x) ;
                elm = elm->next ;
        }
}
