#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int convert_to_int(const char s[])
{
    int len = strlen(s);
    int t = 0, i;
    for (i = 0; i < len; i++){
      printf(" %c=%d ", s[i], s[i]);
        t = t * 10 + s[i] - '0';
    }
    return t;
}

int main(){
  int i, j, len;
  char s[] = "3+7";
  int ans;
  
  ans = convert_to_int(s);
  return 0;
}