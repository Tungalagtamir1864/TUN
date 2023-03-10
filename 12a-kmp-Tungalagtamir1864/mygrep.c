#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int case_insensitive = 0;

/* DFA хүснэгт байгуулах функц: pattern хэвийг боловсруулан
 төгсгөлөгт төлөвт автоматын шилжилтийг dfa-д хадгална. '
 R нийт байж болох тэмдэгтийн тоо буюу ASCII кодын хамгийн 
 дээд хязгаар.*/
void KMP(const char *pattern, int *dfa[], int R, int M){
        /* Функцыг гүйцээ */
        int i, j, X = 0, c;

        //Filling DFA with 0s.
        //niit baij boloh temdegtiin too
        // haih ugiin urt
        //tolower jijig bolgodog
        for(i = 0; i < R; i++){
                for(j = 0; j < M; j++){
                        dfa[i][j] = 0;
                }
        }

        //ylgahgui.
        if(case_insensitive == 0){
                dfa[pattern[0]][0] = 1;

                for(j = 1; j < M; j++){
                        for(c = 0; c < R; c++){
                                dfa[c][j] = dfa[c][X];
                        }
                        dfa[pattern[j]][j] = j + 1;
                        X = dfa[pattern[j]][X];
                }
        }
        else
        {
                dfa[tolower(pattern[0])][0] = 1;

                for(j = 1; j < M; j++){
                        for(c = 0; c < R; c++){
                                dfa[c][j] = dfa[c][X];  
                        }

                        dfa[tolower(pattern[j])][j] = j + 1;
                        X = dfa[tolower(pattern[j])][X];
                }
        }
}

/*
  Функц нь buf доторх тэмдэгтэн цуваанаас index байрлалаас эхлэн
  pattern тэмдэгтийг хайна. Олдвол олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
  case_insensitive = 1 бол том жижиг гэж ялгалгүйгээр тааруулна.
  Мөн мөрний мэдээллийг давхар хариуцаж явна.
  Мөр шилжих үед (*pline)++
  buf     :    Хайлт хийх тэмдэгтэн цуваа
  index   :    Хайлтыг эхлэх индекс
  pattern :    Хайх үг
  dfa     :    dfa хүснэгт
  pline   :    Мөрийн мэдээлэл хадгалах хувьсагчийн хаяг
 */
int find(const char *buf, int index, const char *pattern, int *dfa[], int *pline, int N, int M){
        /* Функцыг гүйцээ */
        int i, j = 0; 

        //If it is case sensitive.
        if(case_insensitive == 0){
                for(i = index; i < N && j < M; i++){
                        if(buf[i] == '\n'){
                                (*pline)++;
                        }

                        j = dfa[buf[i]][j];
                }
        }

        //If it is case insensitive.
        else if(case_insensitive == 1){
                for(i = index; i < N && j < M; i++){
                        if(buf[i] == '\n'){
                                (*pline)++;
                        }

                        j = dfa[tolower(buf[i])][j];
                }
        }

        if(j == M)
                return i - M;
        else
                return -1;
}

int main(int argc, char *argv[]){
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
                pattern = argv[1];  // ylgana
        
        FILE *fin;
        fin = fopen(argv[argc - 1], "r");
        if (fin == NULL) {
                printf("Error openning %s file", argv[argc - 1]);
                exit(-1);
        }
        int len = 0; // Файлд доторх тэмдэгтүүд 
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

        int R = 256; // niit baij boloh temdegtiin too
        int *dfa[256]; //төгсгөлөгт төлөвт автоматын шилжилтийг hadgalna
        int M = strlen(pattern);  // haih ugiin urt

        for (i = 0; i < R; i++)
                dfa[i] = (int *) malloc(sizeof(int) * M); 

        KMP(pattern, dfa, R, M);
        
        do{
                ret = find(buf, ret + 1, pattern, dfa, &line, len, M);
                if (ret != -1) {
                        printf("%d: ", line);
                        /* Олдсон газраас доошоо 5 дээшээ 5 тэмдэгтийг хэвлэнэ. */
                        int L = ret - 5;
                        int R = ret + M /*strlen(pattern)*/ + 5;
                        if (L < 0) L = 0;
                        if (R >= len /*strlen(buf)*/) R = len /*strlen(buf)*/;
                        for (i = L; i <= R; i++)
                                printf("%c", buf[i]);
                        printf("\n");
                }
        } while (ret != -1);

        for (i = 0; i < R; i++)
                free(dfa[i]);
        free(buf);
        return 0;
}
