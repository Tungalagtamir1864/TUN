#include "DS.h"


/*
#define HASH_TABLE_SIZE 1000000
struct HashTable {
        List *h;
        int len;
};
typedef struct HashTable HashTable;

struct Student {
        char ovog[20];
        char ner[20];
        char id[11];
};
typedef struct Student Student;

struct Elm {
        Student x;
        struct Elm *next;
};
typedef struct Elm Elm;

// List бүтэц
struct List {
        Elm *head;
        Elm *tail;
        int len;
};
typedef struct List List;
*/

/*
  Оюутны мэдээлэл оруулах функц: `p_hash`-ын зааж байгаа хайш хүснэгтэд
  `x`-д хадгалсан оюутны мэдээллийг оруулна.
 */
void ht_insert(HashTable *p_hash, const Student x)
{// p_hash zaaj baigaa utgad
        int h = ht_hash(x.id);
        Elm *p_elm = l_search(&p_hash->h[h], x.id); // oyutnii id gaar hayg avna
        if (p_elm == NULL)
                l_push_back(&p_hash->h[h], x);  // null baival medeeleliig togsgold oruulna
}

/*
  Хайш тооцоолох функц: `s` тэмдэгтэн цувааны хайшыг тооцоолоод,
  тооцоолсон хайшыг буцаах функц.
 */
int ht_hash(const char s[])
{
        /*
          Энд функцыг хэрэгжүүл
        */
        // hashing from lecture.
        // ascii
        unsigned int idx = 0, hash = 0;
        // 31 tiin toolliin system 
        while (s[idx] != '\0')
        {
                hash = (hash * 31 + s[idx]);
                idx++;
        }
        return hash % HASH_TABLE_SIZE;
}

/*
  Хайш хүснэгтийн утгуудыг эхлүүлэх функц: 
   Хайш хүснэгтийн бүх элементийн `head`, `tail` утгуудад
  `NULL` оноох ёстой.
 */
void ht_init(HashTable *p_hash)
{
        int i;
        p_hash->h = (List *)malloc (sizeof(List) * HASH_TABLE_SIZE);
        for (i = 0; i < HASH_TABLE_SIZE; i++)
                p_hash->h[i].head = p_hash->h[i].tail = NULL;
}

/*
  Хайх функц: 
  `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж,
  олдсон оюутны хаягийг буцаах функц. Олдохгүй бол `NULL` хаяг буцаана.
 */
Student *ht_search(HashTable *p_hash, const char id[])
{
        /*
          Энд функцыг хэрэгжүүл
        */

        // List iin hamgiin ehnii elementiin haygiig ptr-d uguh stoi.
        Elm *ptr = p_hash->h[ht_hash(id)].head;

        while (ptr != NULL)
        {
                // strcmp ashiglan 2 char iig hoorond ni jishne.

                if (strcmp(ptr->x.id, id) == 0)
                {
                        // Element oldvol haygiig ni butsaana.
                        return &ptr->x;
                }
                // Esreg tohioldold haisaar baih bolno. ptr null boltol
                ptr = ptr->next;
        }
        // Oldohgui bol NULL butsaana.
        return NULL;
}

/*
  Мэдээлэл өөрчлөх функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `x.id`-аар
  оюутныг хайж олоод, овог нэрийг `x.ner`, `x.ovog`-оор солино.
  Олдохгүй бол `x` оюутныг шинээр оруулна.
 */
void ht_update(HashTable *p_hash, const Student x)
{
        /*
          Энд функцыг хэрэгжүүл
        */
        // check if student is not found.
        if (ht_search(p_hash, x.id) == NULL)
        {
                ht_insert(p_hash, x);
        }
        else
        {
                Student *temp = ht_search(p_hash, x.id);
                // *temp->ner = x.ner ;
                // *temp->ovog = x.ovog ;  burrru burruuu
                *temp = x;
        }
}

/*
  Устгах функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж
  олж устгана. Олдохгүй бол юу ч хийхгүй.
 */
void ht_del(HashTable *p_hash, const char id[])
{
        /*
          Энд функцыг хэрэгжүүл
        */
        /*
   Энд функцыг хэрэгжүүл
 */
        int idx = 0;
        Elm *temp = p_hash->h[ht_hash(id)].head;
        // when head is not null
        // we find id then delete it.
        while (temp != NULL)
        {
                if (strcmp(temp->x.id, id) == 0)
                {
                        *temp->x.id = 0;
                        *temp->x.ner = 0;
                        *temp->x.ovog = 0;
                }
                temp = temp->next;
        }
        // idgaa haina.
}

/*
  Хайш хүснэгтийг чөлөөлөх: Ойн цоорхой үүсгэлгүй, бүх элементийг устган, хаягийг чөлөөлнө.
 */
void ht_release(HashTable *p_hash)
{
        int i;
        for (i = 0; i < HASH_TABLE_SIZE; i++)
        {
                while (p_hash->h[i].head != NULL)
                        l_pop_front(&p_hash->h[i]);
        }
        free(p_hash->h);
}

/*
  Оюутны мэдээллийг хэвлэх функц: `p`-ын зааж буй оюутны овог, нэр, ID-г хэвлэнэ.
 */
void student_print(FILE *fout, const Student *p)
{
        if (p == NULL)
                fprintf(fout, "xooson\n");
        else
                fprintf(fout, "%s %s %s\n", p->ovog, p->ner, p->id);
}
