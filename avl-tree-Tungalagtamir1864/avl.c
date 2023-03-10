#include "DS.h"
Elm *node(int x)
{
    Elm *a = malloc(sizeof(Elm));
    a->height = 1;
    a->len = 1;
    a->L = a->R = NULL;
    a->x = x;
    return a;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Elm *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return p->height;
    }
}

int size(Elm *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int r = size(p->R);
    int l = size(p->L);
    return l + r + 1;
}
int getbalance(Elm *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
        return (height(p->L) - height(p->R)); // ondriin zoruu 1 ees hetrehgui
}

Elm *rightRotate(Elm *y)
{
    Elm *x = y->L;  
    Elm *T2 = x->R;  
    y->L = T2; 
    x->R = y;  
    y->height = max(height(y->L), height(y->R)) + 1;
    x->height = max(height(x->L), height(x->R)) + 1;
    y->len = size(y);
    x->len = size(x);
    return x;
}
Elm *leftRotate(Elm *x)
{
    Elm *y = x->R; 
    Elm *T2 = y->L; 
    y->L = x;   
    x->R = T2;   
    x->height = max(height(x->L), height(x->R)) + 1;
    y->height = max(height(y->L), height(y->R)) + 1;
    x->len = size(x);
    y->len = size(y);
    return y;
}
Elm *putElm(Elm *p, int x)
{
    if (x < p->x)
    {
        p->L = putElm(p->L, x);
    }
    else if (x > p->x)
    {
        p->R = putElm(p->R, x);
    }
    else
    {
        return p;
    }
    p->height = max(height(p->L), height(p->R)) + 1;
    p->len++;

    int property = getbalance(p);
    if (property > 1 && x < p->L->x)   //z zh 
    { 
        return rightRotate(p);
    }

    if (property > 1 && x > p->L->x) //z zb
    {      
        p->L = leftRotate(p->L);
        return rightRotate(p);
    }
    if (property < -1 && x > p->R->x) //b bh
    {
        return leftRotate(p);
    }
    if (property < -1 && x < p->R->x) //b zh 
    {
        p->R = rightRotate(p->R);
        return leftRotate(p);
    }
    return p;
}
/*
 `ptree`-ийн зааж байгаа модонд `x` утгыг оруулна.
 Оруулахдаа хоёртын хайлтын модны зарчмаар оруулах б г д оруулсан ө өө
 байрлалаас дээшхи в г эцгийн `len`, `height` утгууд рчл гд н . ө ө өө ө ө ө
 Мод хоосон байсан бол `ptree->root` хаяг рчл гд ж шинээр орсон оройг заана. өө ө ө
 Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэрж лэх йлдл дийг хийнэ. үү ү үү
 */
void avl_put(AVL *ptree, int x)
{
    // Функцийг хэрэгж лнэ үү үү
    if (ptree->root == NULL)
    {
        ptree->root = node(x);
        return;
    }
    else
        ptree->root = putElm(ptree->root, x);
}
/*
 `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг
буцаана.
 Олдохг й бол `NULL` хаягийг буцаана. ү
 Мод дандаа ялгаатай элемент д хадгална гэж зэж болно. үү ү
 */
Elm *get(Elm *p, int x)
{
    if (p == NULL || x == p->x)
        return p;
    if (x > p->x)
    {
        return get(p->R, x);
    }
    else
    {
        return get(p->L, x);
    }
}
Elm *avl_get(const AVL *ptree, int x)
{
    // Функцийг хэрэгж лнэ үү үү
    if (ptree->root == NULL)
    {
        return NULL;
    }
    get(ptree->root, x);
}
/*
 Устгах функц: ТМноос `x` утгыг хайж олоод устгана.
 Олдохг й бол юу ч хийхг й. ү ү
 Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэрж лэх йлдл дийг хийнэ. үү ү үү
 */
Elm *del(Elm *p, int x)
{
    if (p->x < x)
    {
        p->R = del(p->R, x);
    }
    else if (p->x > x)
    {
        p->L = del(p->L, x);
    }
    else
    {
        Elm *tmp;
        if (p->L == NULL)
        {
            tmp = p->R;
            return tmp;
        }
        else if (p->R == NULL)
        {
            tmp = p->L;
            return tmp;
        }
        tmp = p->R;
        while (tmp->L != NULL)
            tmp = tmp->L;
        p->x = tmp->x;
        p->R = del(p->R, tmp->x);
    }
    p->height = max(height(p->L), height(p->R)) + 1;
    p->len--;
    if (p == NULL)
        return p;
    int balance = getbalance(p);
    if (balance > 1 && getbalance(p->L) < 0)// z bh
    {
        p->L = leftRotate(p->L);
        return rightRotate(p);
    }
    if (balance > 1 && getbalance(p->L) >= 0)// z zh
        return rightRotate(p);
    if (balance < -1 && getbalance(p->R) <= 0)// b bh
        return leftRotate(p);
    if (balance < -1 && getbalance(p->R) > 0)// b zh
    {
        p->R = rightRotate(p->R);
        return leftRotate(p);
    }
    return p;
}
void avl_del(AVL *ptree, int x)
{
    // Функцийг хэрэгж лнэ үү үү
    ptree->root = del(ptree->root, x);
}
int min(Elm *p)
{
    Elm *t = p;
    while (t->L != NULL)
    {
        t = t->L;
    }
    return t->x;
}

Elm *delMin(Elm *p)
{
    if (p->L == NULL)
    {
        return p->R;
    }
    p->L = delMin(p->L);
    p->len = size(p);
    return p;
}
/*
 Хамгийн багыг устгах функц: ТМноос хамгийг бага утгыг нь устгах функц.
 Устгасан утгыг буцаана.
 Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэрж лэх йлдл дийг хийнэ. үү ү үү
 */
int avl_delMin(AVL *ptree)
{
    // Функцийг хэрэгж лнэ үү үү
    int tmp = min(ptree->root);
    ptree->root = delMin(ptree->root);
    return tmp;
}
/*
 ТМыг inorder дарааллаар, нэг м р нд нэг утга хэвлэнэ. ө ө
 */
void print_inorder(Elm *p)
{
    if (p == NULL)
    {
        return;
    }
    print_inorder(p->L);
    printf("%d %d %d\n", p->x, p->len, p->height);
    print_inorder(p->R);
}
void avl_inorder(const AVL *ptree)
{
    // Функцийг хэрэгж лнэ үү үү
    print_inorder(ptree->root);
    return;
}
/*
 ТМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
 дэд модонд хэдэн орой байгааг олж буцаана.
 Олдохг й бол -1-ийг буцаана. ү
 */
int avl_size(const AVL *ptree, int x)
{
    // Функцийг хэрэгж лнэ үү
    Elm *a = avl_get(ptree, x);
    if (a == NULL)
        return -1;
    else
        return a->len;
}

/*
 ТМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
 дэд модны нд р хэд байгааг олж буцаана. Олдохг й бол -1-ийг буцаана. ө ө ү
 */
int avl_height(const AVL *ptree, int x)
{
    // Функцийг хэрэгж лнэ үү үү
    Elm *a = avl_get(ptree, x);
    if (a == NULL)
        return -1;
    else
        return a->height;
}
