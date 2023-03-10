#include "DS.h"

//ymar oroi der yvj baigaa 
//k buyu kodiin medeelel
/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, Token x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  TokenElm *elm = malloc(sizeof(TokenElm)) ;
  
  // elm null baival yu ch hiihgui.
  if (elm == NULL){
    return ;
  }
  // Hamgiin suuld element nemeh gej baigaa bolohoor next-g n NULL gej ugnu.
  // elm->x-d x utgaa ugnu.
  elm->x = x ;
  elm->next = NULL ;
  if (p->head == NULL && p->tail == NULL){
    // hervee list hooson baival 
    p->head = p->tail = elm ;
    // head tail 2 2laa elm baina. 
  }
  else {
    // list iin hamgiin suuld elm iig bairluulaad
    p->tail->next = elm ;
    // listiin tail uuruu elm bolno.
    p->tail = elm ;
  }
  p->len++ ;
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, Token x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  TokenElm *elm = malloc(sizeof(TokenElm)) ;
  
  elm->x = x ;
  // Hamgiin urd push hiij bga bolhoor
  // push hiisnii daraa hamgiin ehnii elementiin daraagiin hayg ni 
  // umnuh husnegtiin hamgiin ehnii elementiin hayg baih ystoi.
  elm->next = p->head ;
  if (p->head == NULL && p->tail == NULL){
    p->head = p->tail = elm ;
  }
  else {
    p->head = elm ;
  }
  p->len++ ;

}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, Token x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  if (pos == p->len){
    // hamgiin suuld baival push_Back ;
    l_push_back(p , x) ;
  }
  if (pos == 0){
    // hamgiin urd baival
    l_push_front(p, x) ;
  }
  TokenElm *init_header = p->head ;
  TokenElm *elm = malloc(sizeof(TokenElm)) ;
  elm->x = x ;
  // x utgiig pos bairlald hiihed zaaval iterate hiih heregtei/
  // 
  int i;
  for( i = 1; i < pos; i++){
    init_header = init_header->next ;
  }
  // insertion uildel 
  elm->next = init_header->next ;
  init_header->next = elm ;
  p->len++ ; 
}


/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
  TokenElm *elm = p->head ;
  // head iig ni daraagiin elementiin haygaar solij bna.
  // ingesneer ehnii elementiig archij hayna.
  p->head = p->head->next ;
  if (p->head == NULL){
    p->tail = NULL ;
  }
  // hamgiin urd elementiig pop hiisen bolhoor size 1 eer bagasna
  p->len-- ;
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
  TokenElm *elm = p->head ;
  if (p->head->next == NULL){
    // 1 elementtei baival
    free(p->head) ;
    p->head = NULL ;
    p->tail = NULL ;
  } 
  else {
    while (elm->next != p->tail){
      elm = elm->next ;
    }
    free(p->tail) ;
    elm->next = NULL ;
    p->tail = elm ;
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
  TokenElm *elm = p->head ;
  if (pos == 0){
    // hamgiin ehnii bairlald baival 
    // shuud pop front uildliig hine.

    l_pop_front(p) ;
  }
  if (pos < p->len && pos > 0){
    int i;
    for( i=1 ;i < pos ;i++ ){
      if (elm->next != NULL ){
        elm = elm->next ;
      }
    }
    elm->next = elm->next->next ;
    p->len--  ;
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
        TokenElm *elm = p->head ;
        // List iin buh elementeer guij hevlene.
        // Ingehiin tuld head ees ehleed guine
        while(elm != NULL){
          // elm tugsguld hureegui tohioldold
          // val, op 2oo hevleed iterate hiiged yavaad baina 
          if (elm->x.flag){
            printf("%d", elm->x.val) ;
          }
          else {
            printf("%c", elm->x.op) ;
          }
          // tsaashaa iterate hiine.
          elm = elm->next ;
        }
        // break-line
        printf("\n") ;

}

