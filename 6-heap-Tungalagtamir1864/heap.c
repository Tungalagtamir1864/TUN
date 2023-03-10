#include "DS.h"

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
        int tmp = p->h_len;    // tmp-d odoo bga heap iin urtiig hadgalna
        p->h_arr[p->h_len] = x ;        // heap iin hamgiin suuld x-g oruulna
        p->h_len++ ;    // suuld oruulsan uchir hemjeeg n 1 eer nemne
        swim(p, tmp) ; // heap butets aldagdah uchiraas swim hiij zuv bairand ni oruulna.
}

/*
  Heap бүтцийн swim үйлдэл.
  k нь swim үйлдлийг p-ын зааж буй heap дээр эхлүүлэх индекс.
 */
static void swim(Heap *p, int k)// hovuuleh
{
        // Энд swim үйлдлийг хийнэ
        // etsgeesee ih l baih yum bol deesh n shiljuuleed baina gesen ug
        //estgeesee ih baigaa tohioldold urgeljlen davtagdana
        // etsgeesee ih baival etsegteen solino
        //modnii undes hurtel yvna


        //huuhdeesee baga baiga baih tohiodold 
        while(k >= 0 && less(&p->h_arr[k / 2], &p->h_arr[k]))  // Deeshee swim hiij bna
        {
                Msg tmp = p->h_arr[k] ;         // swim hiigeed zuv bairlaliig ni olood swap hiih ystoi bolhoor
                p->h_arr[k] = p->h_arr[k / 2] ; // msg turliin tmp-d tur p->h_arr[k]-g hadgalj swap hiigeed
                p->h_arr[k / 2] = tmp ; //
                k = k / 2 ; // etseg ruu shiljeed davtana.
        }
}

/*
  Heap бүтцийн sink үйлдэл.
  k нь sink үйлдлийг p-ын зааж буй heap дээр эхлүүлэх индекс.
 */
static void sink(Heap *p, int k)
{
        // Энд sink үйлдлийг хийнэ
        // huuuhedtei baih tohioldold 
    while (2 * k < p->h_len)
    {
        int j = 2 * k ;
        // baruun huuhedtei 
        // len-1 h.suuliin
        if (j < p->h_len - 1 && less(&p->h_arr[j], &p->h_arr[j+1]))
        {
                j++ ;
                // sink hiihdee dooshoo yavah bolhoor ehleed 2 huuhdiinhee ali ihiig olno
                // tegeed ali ih huuhdiigee etsegtei jishne.
        }
        if (!less(&p->h_arr[k], &p->h_arr[j]))
        {
                break ;    // huuhed ni etsgeesee ih bolchvol break; Uchir ni parent dandaa child node oosoo ih baih ystoi.
        }
        // Odoo esreg tohioldold parent node child node oosoo ih bolson uhchiraas swap uildliig hiine.
        Msg tmp = p->h_arr[j] ;
        p->h_arr[j] = p->h_arr[k] ;
        p->h_arr[k] = tmp ;


        k = j ;
    }
}

/*
  p-ын зааж буй heap бүтцээс оройн элементийг гаргаад буцаах функц.
  Гаргасны дараа орой бүрийн хувьд heap зарчим хадгалах ёстой.
 */
Msg delMin(Heap *p)
{
        Msg minim, tmp ;
        // Энд хамгийн багыг гаргах үйлдлийг хийнэ
        minim = p->h_arr[0] ;
        tmp = p->h_arr[0] ; // root node iig hadgalna.
        p->h_arr[0] = p->h_arr[p->h_len - 1] ; // root node-d hamgiin suuliin elementiig ugnu.
        p->h_arr[p->h_len - 1] = tmp ; // hamgiin suuliin elemented (umnuh) root node iig ugnu.
        p->h_len-- ;
        sink(p, 0) ;
        return minim ;
}

