#include "DS.h"

int main()
{
        int x, t, y;
        BST bst;
        bst.root = NULL;
        Elm *p;
        
        while (1) {
                printf("1: put, 2: get, 3: del, 4: delMin, 5: inorder, "
                       "6: rank, 7: size, 8: floor, 9: ceiling, 10: height, 11: exit\n");
                scanf("%d", &t);

                switch (t) {
                case 1:
                        printf("Oruulax utga: ");
                        scanf("%d", &x);
                        bs_put(&bst, x);       // oruulah
                        break;
                case 2:
                        printf("Xandax utga: ");
                        scanf("%d", &x);
                        p = bs_get(&bst, x);  //* Хайх функц: ХХМноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг буцаана.
                                              // Олдохгүй бол `NULL` хаягийг буцаана. Мод дандаа ялгаатай элементүүд хадгална
                                              // гэж үзэж болно. ХХМнд ямарч өөрчлөлт орохгүй.
                        if (p == NULL)
                                printf("Oldsongui\n");
                        else {
                                printf("Utga: %d\n", p->x);
                                printf("len: %d\n", p->len);
                                printf("height: %d\n", p->height);
                        }
                        break;
                case 3:
                        printf("Ustgax utga: ");   // * Устгах функц: ХХМноос `x` утгыг хайж олоод устгана. Олдохгүй бол 
                                                   // юу ч хийхгүй. Устсан оройн нөлөөлөх оройнуудын `len`, `height` утгуудыг шинэчилнэ.
                        scanf("%d", &x);
                        bs_del(&bst, x);
                        break;
                case 4:
                        if (bst.root) {
                                x = bs_delMin(&bst);
                                printf("Ustgasan xamgiin baga utga: %d\n", x);
                        } else
                                printf("Mod xooson\n");
                        break;
                case 5:
                        bs_inorder(&bst);
                        break;
                case 6:
                        printf("Rank olox utga: "); //Зэргийг олох функц: ХХМноос `x` утгаас эрс бага буюу тэнцүү байх хэдэн орой байгааг олж буцаана.
                                                    // Өөрөөр хэлбэл хоёртын хайлтын модны утгуудыг өсөх дарааллаар байрлуулбал `x`-ийг оролцуулаад өмнө 
                                                    //хэдэн тоо байх вэ? гэсэн үг. `x` утга заавал модонд байх албагүй.
                        scanf("%d", &x);
                        y = bs_rank(&bst, x);
                        printf("Rank(%d): %d\n", x, y);
                        break;
                case 7:
                        printf("Xemjee olox utga: ");    //
                        scanf("%d", &x);
                        y = bs_size(&bst, x);
                        printf("Size(%d): %d\n", x, y);
                        break;
                case 8:
                        printf("Dood buxel olox utga: ");
                        scanf("%d", &x);
                        p = bs_floor(&bst, x); // Доод элемент буцаах: XXMноос `x`-ээс бага буюу тэнцүү байх хамгийн их утгын 
                                                //`Elm *` хаягийг олж буцаана. Олдохгүй бол `NULL` хаягийг буцаана.
                        if (p != NULL)
                                printf("Floor(%d): %d\n", x, p->x);
                        else
                                printf("odlsongui\n");
                        break;
                case 9:
                        printf("Deed buxel olox utga: ");
                        scanf("%d", &x);
                        p = bs_ceiling(&bst, x);
                        if (p != NULL)
                                printf("Ceiling(%d): %d\n", x, p->x);
                        else
                                printf("odlsongui\n");
                        break;
                case 10:
                        printf("Undur olox utga: ");
                        scanf("%d", &x);
                        y = bs_height(&bst, x);
                        printf("Height(%d): %d\n", x, y);
                        break;
                case 11:
                        exit(0);
                default:
                        break;
                }
        }
        return 0;
}
