#include <stdio.h>
int fact(int n){
  int x;
  if(n==0)
    return 1;
  x = fact(n-1);
  return n*x;
}
int main(){
  int n=5;
  int ans;
  ans = fact(n);
  return 0;
}