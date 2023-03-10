#include "DS.h"
//#define max(a, b) ((a > b) ? a : b) 


//free hiih yum shig bna
/*
Elm *createNode(int x){
        Elm *s1 = (Elm *) malloc(sizeof(Elm)) ;
        s1->x = x ;
        s1->height = s1->len = 1 ;
        s1->R = s1->L = NULL ;
        return s1 ;
}
*/
void insert(Elm *p, int x)
{
        if (p->x > x)// ih bol baruun baga bol zuun
        {
                if (p->L == NULL)// root zuun huuhed n null
                {
                        Elm *s1 = (Elm *)malloc(sizeof(Elm));
                        s1->x = x;
                        s1->height = s1->len = 1;
                        s1->R = s1->L = NULL;
                        ////////////
                        p->L = s1;
                }
                else
                        insert(p->L, x);
        }
        else
        {
                if (p->R == NULL)
                {
                        Elm *s1 = (Elm *)malloc(sizeof(Elm));
                        s1->x = x;
                        s1->height = s1->len = 1;
                        s1->R = s1->L = NULL;
                        p->R = s1;
                }
                else
                        insert(p->R, x);  // baruun huuhdee root bolgood 
        }
/*
        bs_put(&bst, 5);    
        bs_put(&bst, 3);        
        bs_put(&bst, 8);   
        bs_put(&bst, 2);   
        bs_put(&bst, 9);                  
                                                    h  l
                        5                  1.   5-  3  5 
                    3      8               2.   3-  2  2
                2     -   -    9           3.   8   2  2
                                           4.   2   1  1
                                           5.   9   1  1


                 baruun zuun huuhdiig n toolood ali ehiiig n avna
                 elment nemegdej baih yum  bol urt                           
*/
        

        int lc, rc;
        lc = p->L == NULL ? 1 : p->L->height + 1; 
        rc = p->R == NULL ? 1 : p->R->height + 1;
        p->height = lc > rc ? lc : rc;
        p->len++;
}
void bs_put(BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        if (ptree->root == NULL)
        { // hervee root null buyu hooson mod bol x ni root bolno.
                Elm *s1 = (Elm *)malloc(sizeof(Elm));
                s1->x = x;
                s1->height = s1->len = 1;
                s1->R = s1->L = NULL;
                ptree->root = s1;
                return;
        }
        insert(ptree->root, x);
}





/*
  `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
  Мод дандаа ялгаатай элементүүд хадгална гэж үзэж болно.
 */

Elm *get_elm(Elm *ptr, int x){
        if ( ptr == NULL || x == ptr->x)
                return ptr;
        if (x > ptr->x)
                return get_elm(ptr->R, x);
        else
                return get_elm(ptr->L, x);

}
Elm *bs_get(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        get_elm(ptree->root, x) ;
}
/*
  Устгах функц: ХХМноос `x` утгыг хайж олоод устгана.
  Олдохгүй бол юу ч хийхгүй.
 */

Elm *delete(Elm *p, int x){
        Elm *temp;
        if (p == NULL)
                return p;

        if (x < p->x)
                p->L = delete(p->L, x);

        else if (x > p->x)
                p->R = delete(p->R, x);
        else
        {// olson
                if (p->L == NULL)
                {
                        temp= p->R;
                        return temp;
                }
                else if (p->R == NULL)
                {
                        temp = p->L;
                        return temp;
                }
                temp = p->R;
                while (temp->L != NULL)
                        temp = temp->L;

                p->x = temp->x;
                p->R = delete(p->R, p->x);
        }
        int lc, rc;
        lc = p->L == NULL ? 1 : p->L->height + 1;
        rc = p->R == NULL ? 1 : p->R->height + 1;
        p->height = lc > rc ? lc : rc;
        p->len--;
        return p;
}

void bs_del(BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        ptree->root = delete(ptree->root, x) ;
}
/*
  Хамгийн багыг устгах функц: ХХМноос хамгийг бага утгыг нь устгах функц.
  Устгасан утгыг буцаана.
 */
int min(Elm *p)
{
        Elm *temp = p;
        while (temp->L != NULL)
        {
                temp = temp->L;
        }
        return temp->x;
}
Elm *delmin(Elm *p){
        if (p->L == NULL){  // h.baga n root
                return p->R ;
        }
        p->L = delmin(p->L) ;// left utgiig n ogno 
        p->len--; // duusaad dahiad ajlaad bainaa 
        return p ;  // bas holbogdchood bnaaa sad sad
}

int bs_delMin(BST *ptree)
{
        // Функцийг хэрэгжүүлнэ үү
        int t;
        t = min(ptree->root) ;
        ptree->root = delmin(ptree->root) ;
        return t ;
}

/*
  ХХМыг inorder дарааллаар, нэг мөрөнд нэг утга хэвлэнэ.
 */
void inorderz(Elm *ptr){
        if (ptr == NULL){
                return ;
        }
        inorderz(ptr->L) ;
        printf("%d %d %d\n", ptr->x, ptr->len, ptr->height) ;
        inorderz(ptr->R) ;
        
}
// l ro r
void bs_inorder(const BST *ptree)
{
        // Функцийг хэрэгжүүлнэ үү
        inorderz(ptree->root) ;

}



/*
  ХХМноос `x` утгаас эрс бага буюу тэнцүү байх хэдэн орой байгааг олж буцаана.
  Өөрөөр хэлбэл хоёртын хайлтын модны утгуудыг өсөх дарааллаар байрлуулбал
  `x`-ийг оролцуулаад өмнө хэдэн тоо байх вэ? гэсэн үг.
  `x` утга заавал модонд байх албагүй.
 */

int lo_rank(Elm *ptr, int x) {
        if (ptr == NULL){
                return 0 ;
        }
        if (ptr->x > x){
                return lo_rank(ptr->L, x) ;
        }
        int left;
        left = ptr->L == NULL ? 1 : ptr->L->len + 1;
        return left + lo_rank(ptr->R, x);
        
}
int bs_rank(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        if (ptree->root != NULL){
                return lo_rank(ptree->root, x) ;
        }
        
}


/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модонд хэдэн орой байгааг олж буцаана.
  Олдохгүй бол -1-ийг буцаана.
 */
int bs_size(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү

        Elm *ptr = bs_get(ptree, x) ; // should working fine. 
        return ptr == NULL ? -1 : ptr->len ;
}

/*
  XXMноос `x`-ээс бага буюу тэнцүү байх хамгийн их утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */

Elm *flooring(Elm *ptr, int x){
        if (ptr == NULL) 
                return NULL ;
        if (ptr-> x > x){  // 10 > 8   ihdeed
                return flooring(ptr->L, x) ; 
        }
        else if (ptr->x == x){
                return ptr ;
        }
        else {
                Elm *t = flooring(ptr->R, x) ;
                if (t == NULL){
                        return ptr ;
                }
                else {
                        return t ;
                }
        }
}

Elm *bs_floor(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        // return ptree->root == NULL ? NULL : flooring(ptree->root, x) ;
        if (ptree->root == NULL)
                return NULL;
        else
                return flooring(ptree->root, x);
}


/*
  XXMноос `x`-ээс их буюу тэнцүү байх хамгийн бага утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *ceiling(Elm *ptr, int x){
        if (ptr == NULL) {
                return NULL ;
        }
        if (ptr->x < x){  // bagadaad
                return ceiling(ptr->R, x) ;
        }
        else if (ptr->x == x){
                return ptr ;
        }
        else {
                Elm *t = ceiling(ptr->L, x); // ihdeed
                if (t == NULL)
                        return ptr;
                else
                        return t;
        }
}

Elm *bs_ceiling(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        // return ptree->root == NULL ? NULL : ceiling(ptree->root, x) ;
        if (ptree->root == NULL)
                return NULL;
        else
                return ceiling(ptree->root, x);
}

/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модны өндөр хэд байгааг олж буцаана. Олдохгүй бол -1-ийг буцаана.
 */
int bs_height(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        Elm *ptr = bs_get(ptree, x) ;
        return ptr == NULL ? -1 : ptr->height;
}
