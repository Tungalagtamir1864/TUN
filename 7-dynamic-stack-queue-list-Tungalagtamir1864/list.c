#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  Elm *st = malloc(sizeof(Elm)) ;
  st->x = x ;
  st->next = NULL ;
  if (p->head == NULL && p->tail == NULL) {
          p->head = p->tail = st ;
  }
  else {
          p->tail->next = st ;
          p->tail = st ;  
  }

  p->len++ ;
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  Elm *st = malloc(sizeof(Elm)) ;
  st->x = x ;
  st->next = p->head ;
    if (p->head == NULL && p->tail == NULL) {
          p->head = p->tail = st ;
  }
  else {
        p->head = st ;
  }
  
  p->len++ ;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, int x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  // saruul gedeg nertei temp heregtei ym bna. Odoo harjii, jinken goe yaana hha.
  // 2 special case bga ni hamgiin urd baih || hamgiin ard baih 
  if (pos == 0){
    l_push_front(p, x) ;
    return ;
  }
  if (pos == p->len){
    l_push_back(p, x) ;
    return ;
  }
  // pos-th element ruu shuud handaj chadahgui bolhoor iterate hiij guihees uur argagu.
    Elm *st = (Elm *) malloc(sizeof(Elm)) ;
    Elm *saruul = p->head ;
    st->x = x ;
    for(int i=1; i<pos;  i++){
        saruul = saruul->next ;
    }
    st->next = saruul->next ;
    saruul->next = st ;


    p->len++ ;



}


/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
   Elm *st = p->head  ;
    p->head = p->head->next ;
    if (p->head == NULL) {      //HOLY SH. zuv nuhtsul bsn bn
      p->tail = NULL ;
    }
    p->len-- ;
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
 Elm *st = p->head ;
  // shuud tail-d utga onooj bolohgui ym bna.
  // uchir ni umnuh haygaa medeh heregtei bolchihiin bn.
  // hervee list hooson bol:
  if(p->head->next == NULL){
    p->head = p->tail = NULL ; // same as p->head = NULL, p->tail = NULL ;
  }
  else {
  while(st->next != p->tail) {
          st = st->next ;   // iterate hiij bn. 
      }
      st->next = NULL ;  // not sure. 
      p->tail = st ;
      }
      p->len-- ;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
    Elm *st = p->head ; //wtf is this 
    // inserttei adil
    if (pos == 0){
      l_pop_front(p) ;
    }

    if (pos > 0 && pos < p->len){
      for(int i=1; i<pos; i++){
        if (st->next !=  NULL) {
              st = st->next ;
        }
      }
    st->next = st->next->next ;
    p->len-- ;
    }

}

/*
  p-ийн зааж буй List-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void l_print(List *p)
{
        /* Энд хэвлэх үйлдлийг хийнэ үү */
  Elm *st = p->head ;
  while(st != NULL) {
    printf("%d\n", st->x) ;
    st = st->next ;

  }
}

/*
  p-ийн зааж буй List-с x тоог хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, int x)
{
	     Elm *st ;
       int boo = 0 ; 
       for(st = p->head; st != NULL; st = st->next) {
            if (st->x == x){    // oldvol break, C deer boolean bdgui ym bn
                boo = 1 ;
              break ;
            }
       }
       if (boo == 1){
          return st ;
       }
       else {
          return NULL ;
       }
}
