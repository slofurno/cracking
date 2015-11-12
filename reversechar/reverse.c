#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **args){

  if (argc !=2){
    printf("%s\n", "bad params");
    return -1;
  }

  char *s = args[1];

  int len = 0;
  while(s[len]!='\0'){
    len++;
  }

  char temp;
  int mid = len/2;

  for(int i =0; i<mid;i++){
    temp = s[i];
    s[i]=s[len-i-1];
    s[len-i-1]=temp;
  }

  printf("%s \n", s);

  return 0;
}
