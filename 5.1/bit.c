#include <stdlib.h>
#include <stdio.h>


void print_bits(int n){
  int i;
  for(i = 31; i>=0;i--){
    printf("%d ", (n>>i)&1);
  }
  printf("\n");

}


int main(int argc, char **args){

  //char *first = args[1];
  //long tevs = atoi(first);

  //printf("%s parsed as %d\n", first, tevs);

  int N = 255;
  int M = 19;
  int j = 6;
  int i = 2;

  print_bits(N);
  print_bits(M);

  int mask=0;
  int k = 0;

  for(k=0;k<=j-i;k++){
    mask = (mask << 1) + 1;
  }

  printf("%d\n", mask);

  int result=N&~(mask<<i);
  print_bits(result);
  result|=M<<i;

  printf("%d\n", result);
  print_bits(result);

}
