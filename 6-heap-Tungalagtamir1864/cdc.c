#include <stdio.h>
#include <string.h>

struct Msg {
        char text[100];
        int priority, time;
};
typedef struct Msg Msg;

struct Array {
        Msg a[100000];
        int len;
};


// Heap
struct Heap {
        struct Array heap;
};
typedef struct Heap Heap;
#define h_arr heap.a
#define h_len heap.len


static void swim(Heap *p, int);
static void sink(Heap *p, int);

/*
  Хоёр зурвасын чухлыг харьцуулах функц.
  b нь илүү чухал бол 1, бусад үед 0-ыг буцаах функц.
  Өөрөөр хэлбэл a < b үйлдэл юм.
*/
int less(const Msg *a, const Msg *b)
{
        // Энд жиших үйлдийг хийнэ
        if (a->priority > b->priority)
        {
                return 1 ;
        }
        else if (a->priority < b->priority)
        {
                return 0 ;
        }
        else
        {
        // 2 priority-goo hoorond ni jisheed shuud yalgasan.
                if (a->time > b->time)   // hervee adilhan priority toi baih ym bol turuulj orson ni chuhal baih ysoti.
                {
                        return 1 ;     // uchraas time aar ni haritsuulj ali ni turuulj orsniig shalgana.
                }
                else
                {
                        return 0;
                }
        }

}

/*
  Оруулах функц. heap зарчмаар чухлын дарааллыг баримтлан оруулна.
  Ингэхдээ хамгийн чухал зурвас heap-ын оройд хадгалагдана.
  x зурвасыг p-ын зааж буй heap бүтцэд оруулна.
 */
void insert(Heap *p, const Msg x)
{
        // Энд оруулах үйлдлийг хийнэ
        // Энд оруулах үйлдлийг хийнэ
        int tmp = p->h_len ;    // tmp-d odoo bga heap iin urtiig hadgalna
        p->h_arr[p->h_len] = x ;        // heap iin hamgiin suuld x-g oruulna
        p->h_len++ ;    // suuld oruulsan uchir hemjeeg n 1 eer nemne
        swim(p, tmp) ; // heap butets aldagdah uchiraas swim hiij zuv bairand ni oruulna.
}

/*
  Heap бүтцийн swim үйлдэл.
  k нь swim үйлдлийг p-ын зааж буй heap дээр эхлүүлэх индекс.
 */
static void swim(Heap *p, int k)
{
        // Энд swim үйлдлийг хийнэ
        while(k >= 0 && less(&p->h_arr[k / 2], &p->h_arr[k]))  // Deeshee swim hiij bna
        {
                Msg tmp = p->h_arr[k] ;         // swim hiigeed zuv bairlaliig ni olood swap hiih ystoi bolhoor
                p->h_arr[k] = p->h_arr[k / 2] ; // msg turliin tmp-d tur p->h_arr[k]-g hadgalj swap hiigeed
                p->h_arr[k / 2] = tmp ; //
                k = k / 2 ; // etseg ruu shiljeed davtana.
        }
}
Heap hp;        // Heap бүтэц 100000 x sizeof(Msg) хэмжээ эзлэнэ

int main()
{
        int n, i;
        scanf("%d", &n);
        char cmd[5];
        Msg x;
                for (i = 0; i < n; i++) {
                scanf("%s", cmd);
                if (strcmp(cmd, "PUT") == 0) {
                        // PUT командаар heap-д оруулна
                        scanf("%s%d", x.text, &x.priority);
                        x.time = i;
                        insert(&hp, x);
                } else if (strcmp(cmd, "GET") == 0) {
                        // GET командаар heap-ээс гаргана
                        x = delMin(&hp);
                        printf("%s\n", x.text);
                }
        }
        
}