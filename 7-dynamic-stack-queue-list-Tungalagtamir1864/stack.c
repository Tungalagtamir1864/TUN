#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
        /* Энд оруулах үйлдлийг хийнэ үү */
        // Elm butetsiin hemjeegeer memory nuutslunu. 
        struct Elm *st = (struct Elm *) malloc(sizeof(Elm)) ;
        st->x = x ;
        // stack iin next ni umnuh elementiihee haygiig hadgalah ystoi. 
        st->next = p->top ;     // end stack suuld orson ni turuulj garah ystoi bolhoor
        p->top = st ;           // suuld orson element umnuh elementiihee haygiig hadgalsan bolhoor
        p->len++ ;              // hamgiin deer bga element bolson gsn ug. 
}       // hamgiin deer ni 1 element nemegdej bga bolhoor hemjee ni 1 eer nemegdene;
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
        /* Энд гаргах үйлдлийг хийнэ үү */
        struct Elm *st = p->top ;// hamgiin deer bga elementiig zaaj ugch bna.
        p->top = st->next ; // top deer bga element garch baigaa bolhoor st iin daraachiin 
        p->len-- ;      // elementiin haygiig zaaj uguud hemjeegee 1 eer bagasgaj pop hiine.
}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p)
{
        /* Энд хэвлэх үйлдлийг хийнэ үү */
        struct Elm * st = p->top ;      // stack-d deerees dooshoo yavlaa.
        while (st != NULL) {    
                printf("%d\n", st->x) ; // stackiin buh elemenenteer guigeed ter top bolgoniihoo 
                st = st->next ; // x utgiig hevleed bolson bol, next ruugee shiljeed yoroolruuga yavna.
        }
}
