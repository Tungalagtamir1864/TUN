#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
        /* Энд оруулах үйлдлийг хийнэ үү */
        struct Elm *st = (struct Elm *) malloc(sizeof(Elm)) ;
        st->x = x ;     // shine linked list uusgej bna. 
        st->next = NULL ;       // hamgiin suuliin element bolhoor next ni null bna.
        if (p->tail == NULL && p->head == NULL) { // check if queue is empty ;
                p->head = p->tail = st ;
        }
        else {
                p->tail->next = st ; // tail elementiin next-d suuld uusgesen elementiinhe haygiig ugnu
                p->tail = st ; // tgd tail ni saynii suuld uusgesen element bolno        
                }
         
        p->len++ ;      // hamgiin ard ni element nemj oruulsan bolhoor size ni 1 eer nemegdeh ystoi
} 

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
        /* Энд гаргах үйлдлийг хийнэ үү */
        struct Elm *st ; 
        p->head = p->head->next ; // hamgiin ehnii elementiin haygiig 2dohoor ni solino.
        if (p->head == NULL) {
                p->tail = NULL ;    // AAAAA ENE NUHTSUL MINII TARHIIG DEAD BOLGOLOOOOOO.
        }
        p->len-- ;
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
        /* Энд хэвлэх үйлдлийг хийнэ үү */
        struct Elm * st  = p->head ;    //Stack tai adilhanaar head-ees tail hurtel yavchina
        while(st != NULL) {     // tail iin next deer hurvel davtalt zogsono. 
                printf("%d\n", st->x) ;   // ter hurtel taarsan buh linked list iinhee value-g hevlene
                st = st->next ; // daraagiin linked list ruu shiljine 
        }
}
