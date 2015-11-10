#include <stdlib.h>
#include <stdio.h>

int main(){

  int arr1[30];
  int arr2[15];

  int i;
  int j =0;
  for(i = 0;i<15;i++){
    arr1[i]=j++;
    arr2[i]=j++;
  }

  int k = 29;
  i = 14;
  j = 14;

  while(k>=0){
    if (j<0 || (i>=0 && arr1[i]>arr2[j])){
      arr1[k]=arr1[i];
      i--;
    }else{
      arr1[k]=arr2[j];
      j--;
    }

    k--;
  }

  for(i=0;i<30;i++){
    printf("%d ", arr1[i]);
  }

  return 0;
}
