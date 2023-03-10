#include "DS.h"
/*
  p-ийн зааж буй CBTree-д x утгыг оруулна

        5
      3   8
    1   4
    5 3 8 1 4
*/
// search insert remove
void cb_push(CBTree *p, int x)
{
  /* Энд оруулах үйлдлийг хийнэ үү */
  p->cb_arr[p->cb_len] = x;
  p->cb_len++;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны зүүн хүүгийн индексийг буцаана.
  Зүүн хүү байхгүй бол -1 буцаана.
*/
int cb_left(const CBTree *p, int idx)
{
  /* Энд зүүн хүүхдийн индексийг буцаах үйлдлийг хийнэ үү
  5
3   8
1   4
5 3 8 1 4

0 1 2 3 4
zuun 2i+1
baruun 2i+2
  */
  if (2 * idx + 1 < p->cb_len)
  {
    return 2 * idx + 1;
  }
  else
  {
    return -1;
  }
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны баруун хүүгийн индексийг буцаана.
  Баруун хүү байхгүй бол -1 буцаана.
*/
int cb_right(const CBTree *p, int idx)
{
  /* Энд баруун хүүхдийн индексийг буцаах үйлдлийг хийнэ үү */
  if (2 * idx + 2 < p->cb_len)
  {
    return 2 * idx + 2;
  }
  else
  {
    return -1;
  }
}

/*
  p-ийн зааж буй CBTree-с x тоог хайн
  хамгийн эхэнд олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
*/
int cb_search(const CBTree *p, int x)
{
  /* Энд хайх үйлдлийг хийнэ */
  int i;
  for (i = 0; i < p->cb_len; i++)
  {
    if (p->cb_arr[i] == x)
    {
      return i;
    }
  }
  return -1;
}

/*

  +
  Өвөг эцэг бүрийг нэг шинэ мөрөнд хэвлэнэ. Өвөг эцэгийг доороос дээшхи дарааллаар хэвлэнэ.
*/
void cb_ancestors(const CBTree *p, int idx)
{
  /* Энд өвөг эцгийг олох үйлдлийг хийнэ үү
  5
3   8
1   4
5 3 8 1 4

0 1 2 3 4
etsgiin index (i-1)/2
  */
  if (idx < p->cb_len && idx > 0)
  {
    int ancestor = (idx - 1) / 2; // current ancestor
    // but we are not printing current ancestor since current ancestor is not counted as ancestor
    if (ancestor >= 0)
    {
      printf("%d\n", p->cb_arr[ancestor]); // print ancestor'th element from array
      cb_ancestors(p, ancestor);           // recursively find all ancestors
    }
  }
}

/*
  p-ийн зааж буй CBTree-ийн өндрийг буцаана
        5
      3   8
    1   4
    5 3 8 1 4

    0 1 2 3 4
   ondor-etsgeer n hooh
   2i+1
*/
int cb_height(const CBTree *p)
{
  /* Энд өндрийг олох үйлдлийг хийнэ */
  int i = 0;
  int count = 0;
  while (i < p->cb_len)
  {
    i = 2 * i + 1;
    count++;
  }
  return count;
}

/*
  p-ийн зааж буй CBTree-д idx оройны ах, дүү оройн дугаарыг буцаана.
  Тухайн оройн эцэгтэй адил эцэгтэй орой.
  Ах, дүү нь байхгүй бол -1-г буцаана.
*/
int cb_sibling(const CBTree *p, int idx)
{
  /* Энд ах, дүүг олох үйлдлийг хийнэ үү */
  if (idx == p->cb_len - 1 && idx % 2 == 1)
  {
    return -1;
  }
  else
  {
    if (idx < p->cb_len && idx > 0)
    {
      if (idx % 2 == 1)
        return idx + 1;
      else
        return idx - 1;
    }
    else
      return -1;
  }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
         5
      3     8
    1   4 6   12
    5 3 8 1 4 6 12

    0 1 2 3 4

pre order---5 3 1 4 8  6 12   rt l r
in order ---1 3 4 5 6 8 12    l rt r
post order--1 4 3 6 12 8 5    l r rt
*/
void cb_preorder(const CBTree *p, int idx)
{
  /* Энд pre-order-оор хэвлэх үйлдлийг хийнэ үү */
  if (p->cb_len > idx)
  {
    printf("%d\n", p->cb_arr[idx]);
    cb_preorder(p, idx * 2 + 1); // left node ;
    cb_preorder(p, idx * 2 + 2); // right node ;
  }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_inorder(const CBTree *p, int idx)
{
  /* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
  if (p->cb_len > idx)
  {
    cb_inorder(p, idx * 2 + 1);
    printf("%d\n", p->cb_arr[idx]); // Finished processing left node
    cb_inorder(p, idx * 2 + 2);
  }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
 */
void cb_postorder(const CBTree *p, int idx)
{
  /* Энд post-order-оор хэвлэх үйлдлийг хийнэ үү */
  if (p->cb_len > idx)
  {
    cb_postorder(p, idx * 2 + 1);
    cb_postorder(p, idx * 2 + 2);
    printf("%d\n", p->cb_arr[idx]); // Finished processing binary nodes
  }
}

/*
  p-ийн зааж буй CBTree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно.
  Навч тус бүрийн утгыг шинэ мөрөнд хэвлэнэ.
  Навчыг зүүнээс баруун тийш олдох дарааллаар хэвлэнэ.
*/
void cb_leaves(const CBTree *p, int idx)
{
  /* Энд навчуудыг үйлдлийг хийнэ үү */
  if (p->cb_len > idx)
  {
    if (idx * 2 + 1 > p->cb_len - 1)
      printf("%d\n", p->cb_arr[idx]);
    cb_leaves(p, idx * 2 + 1); // they are actually correct
    cb_leaves(p, idx * 2 + 2);
  }
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройноос доошхи бүх үр садыг хэвлэнэ.
  Тухайн орой өөрөө үр сад болохгүй.
  Үр, сад бүрийг нэг шинэ мөрөнд хэвлэнэ. Үр садыг pre-order дарааллаар хэлэх ёстой.
*/
void cb_descendants(const CBTree *p, int idx)
{
  /* Энд үр садыг олох үйлдлийг хийнэ үү */
  if (p->cb_len > idx)
  {
    cb_preorder(p, idx * 2 + 1);
    cb_preorder(p, idx * 2 + 2);
  }
}

/*
  p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
  CBTree-д өөрчлөлт оруулахгүй.
*/
int cb_size(const CBTree *p)
{
  /* Энд хэмжээг олох үйлдлийг хийнэ үү */
  return p->cb_len; // Just returning length is enough i guess ;
}

/*
  p-ийн зааж буй CBTree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
  x тоо олдохгүй бол -1-г буцаана.
          5
      3     8
    1   4 6   12

    5 3 8 1 4 6 12

    0 1 2 3 4 5 6
*/
int cb_level(const CBTree *p, int x)
{
  /* Энд түвшинг i = ийг хийнэ үү */
  int ancestor = 0, i;
  for (i = 0; i < p->cb_len; i++)
  {
    if (p->cb_arr[i] == x)
    {
      while (i != 0)
      {
        ancestor++;
        i = (i - 1) / 2; // could've used cb_search function.
      }
      return ancestor;
      break;
    }
    if (i == p->cb_len - 1)
    { //
      return -1;
    }
  }
}
int cb_maxx(const CBTree *p)
{
  int temp = p->cb_arr[0], i;
  for (i = 0; i < p->cb_len; i++)
  {
    if (p->cb_arr[i] > temp)
    {
      temp = p->cb_arr[i];
    }
  }
  return temp;
}