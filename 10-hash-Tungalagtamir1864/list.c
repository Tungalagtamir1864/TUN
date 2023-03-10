#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, Student x)
{
  /* Энд оруулах үйлдлийг хийнэ үү */
  /* Энд оруулах үйлдлийг хийнэ үү */
  Elm *st = malloc(sizeof(Elm));
  st->x = x;
  st->next = NULL;
  if (p->head == NULL && p->tail == NULL)
  {
    p->head = p->tail = st;
  }
  else
  {
    p->tail->next = st;
    p->tail = st;
  }

  p->len++;
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, Student x)
{
  /* Энд оруулах үйлдлийг хийнэ үү */

  Elm *st = malloc(sizeof(Elm));
  st->x = x;
  st->next = p->head;
  // check if null or not (hooson)
  if (p->head == NULL && p->tail == NULL)
  {
    p->head = p->tail = st;
  }
  else
  {
    p->head = st;
  }

  p->len++;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, Student x, int pos)
{
  /* Энд оруулах үйлдлийг хийнэ үү */
  /* Энд оруулах үйлдлийг хийнэ үү */
  // hamgiin urd baival hamgiin urd nemne.
  if (pos == 0)
  {
    l_push_front(p, x);
    return;
  }
  // hamgiin suuld baival hamgiin suuld nemne.
  if (pos == p->len)
  {
    l_push_back(p, x);
    return;
  }
  Elm *st = (Elm *)malloc(sizeof(Elm));
  Elm *tami = p->head;
  st->x = x;
  for (int i = 1; i < pos; i++)
  {
    tami = tami->next;
  }

  st->next = tami->next;
  tami->next = st;

  p->len++;
}

/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
  /* Энд гаргах үйлдлийг хийнэ үү */
  Elm *st = p->head;
  p->head = p->head->next;
  if (p->head == NULL)
  {
    p->tail = NULL;
  }
  p->len--;
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
  /* Энд гаргах үйлдлийг хийнэ үү */

  Elm *st = p->head;

  if (p->head->next == NULL)
  {
    p->head = p->tail = NULL; // same as p->head = NULL, p->tail = NULL ;
  }
  else
  {
    while (st->next != p->tail)
    {
      st = st->next; // iterating through.
    }
    st->next = NULL;
    p->tail = st;
  }

  p->len--;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
  /* Энд гаргах үйлдлийг хийнэ үү */
  Elm *st = p->head;
  if (pos == 0)
  {
    l_pop_front(p);
  }
  if (pos > 0 && pos < p->len)
  {
    for (int i = 1; i < pos; i++)
    {
      if (st->next != NULL)
      {
        st = st->next;
      }
    }
    st->next = st->next->next;
    p->len--;
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
  Elm *st = p->head;
  while (st != NULL)
  {
    printf("%d\n", st->x);
    st = st->next;
  }
}

/*
  p-ийн зааж буй List-с id-тай оюутныг хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, const char id[])
{
  /*
    Энд хайх үйлдлийг хийнэ үү.
   */
  Elm *temp = p->head;

  // we are iteraing here.
  while (temp != NULL)
  {
    // we must use strcmp to compare chars ;

    if (strcmp(temp->x.id, id) == 0)
    {
      return temp;
    }
    // go to next element ;
    temp = temp->next;
  }
  return NULL;
}
