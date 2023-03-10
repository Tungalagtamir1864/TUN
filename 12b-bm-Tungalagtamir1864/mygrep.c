#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int case_insensitive = 0;
int max(int x, int y){
        return (x > y ? x : y) ;
}

int sens(const char c){
        if (case_insensitive){
                // A = 65 ;
                // ...
                // Z = 90 ;
                if (c >= 'A' && c <= 'Z'){
                        // 
                        return c | 32 ;
                }
        }
        return c ;
}
/*
  Шилжилтийн хүснэгтийг байгуулах функц
 */
void BM(const char *pattern, int right[])
{
        /*
          Функцыг гүйцээ
         */
        
        int j ; 
        int R = 256 ;
        int p_length = strlen(pattern) ;

        // right husnegtiig -1 eer duurgej baina.
        // initialization hiij bna gsn ug.
        for(int i=0 ;i < R ; i++){
                right[i] = -1 ;
        }
        /* suuld garj irsen char iig utgaar ni solih */
        for(j = 0 ; j < p_length; j++){
                right[pattern[j]] = j ; 
        }
}

/*
  Функц нь buf доторх тэмдэгтэн цуваанаас index байрлалаас эхлэн
  pattern тэмдэгтийг хайна. Олдвол олдсон индексийг буцанаа.
  Олдохгүй бол -1 утгыг буцаана.
  case_insensitive = 1 бол том жижиг гэж ялгалгүйгээр тааруулна.
  Мөн мөрний мэдээллийг давхар хариуцаж явна.
  Мөр шилжих үед (*pline)++

  buf     :    Хайлт хийх тэмдэгтэн цуваа
  n       :    buf-ын урт
  index   :    Хайлтыг эхлэх индекс
  pattern :    Хайх үг
  m       :    pattern-ны урт
  right   :    шилжилтийн хүснэгт
  pline   :    Мөрийн мэдээлэл хадгалах хувьсагчийн хаяг
 */
int find(const char *buf, int n, int index, const char *pattern, int m, int right[], int *pline)
{
        /*
          Функцыг гүйцээ
         */
        /* */ 
        int j ;
        int i = index ; 
        int tmp ; 
        int skip ; 

        for(i = index ; i<= n - m; i += skip){
                j = m - 1 ;
                while (j >= 0 && sens(pattern[j]) == sens(buf[i + j])){
                        j-- ;
                } 
                if (j < 0){
                        for(tmp = index; tmp < i; tmp++){
                                if (buf[tmp] == '\n'){
                                        (*pline)++ ;
                                }
                        }
                        return i ;
                }
                else {
                        skip = max(1, j - right[sens(buf[i+j])]) ;
                }
        }
        return -1;
}
int main(int argc, char *argv[])
{
        // Аргументийн тоо ядаж 3 байх ёстой.
        if (argc < 3) {
                printf("%s [-i] pattern FILE", argv[0]);
                exit(-1);
        }

        const char *pattern;
        if (argc > 3 && strcmp("-i", argv[1]) == 0) {
                case_insensitive = 1; // Том жижгийг хайхрахгүй адил гэж үзнэ.
                pattern = argv[2];
        } else
                pattern = argv[1];
        
        FILE *fin;
        fin = fopen(argv[argc - 1], "r");
        if (fin == NULL) {
                printf("Error openning %s file", argv[argc - 1]);
                exit(-1);
        }
        int len = 0;
        char ch;                 
        while (!feof(fin)) {
                ch = fgetc(fin);
                len++;          // Файлд доторх тэмдэгтүүдийг тоолъё.
        }
        char *buf;
        buf = (char *) malloc(sizeof(char) * (len + 1)); // Энд тэмдэгтүүдийг хадгална
        fseek(fin, 0, SEEK_SET);                        // Файл заагчийг буцаад эхлэлд нь аваачна.
        int i = 0;
        while (!feof(fin))
                buf[i++] = fgetc(fin); // Өгөгдлийг уншиж байна.
        buf[len - 1] = 0;              /* тэмдэгт мөр төгсгөл заагч */
        int ret = -1;
        int line = 0;


        int R = 256;
        int right[R];
        int m = strlen(pattern);
        BM(pattern, right);
        
        do {
                ret = find(buf, len - 1, ret + 1, pattern, m, right, &line);
                if (ret != -1) {
                        printf("%d: ", line);
                        /*
                          Олдсон газраас доошоо 5
                          дээшээ 5 тэмдэгтийг хэвлэнэ.
                         */
                        int L = ret - 5;
                        int R = ret + strlen(pattern) + 5;
                        if (L < 0) L = 0;
                        if (R >= len) R = len - 1;
                        for (i = L; i <= R; i++)
                                printf("%c", buf[i]);
                        printf("\n");
                }
        } while (ret != -1);

        free(buf);
        return 0;
}
