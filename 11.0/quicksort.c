#include <stdlib.h>
#include <stdio.h>

//typedef int(*comparer)(const void *, const void *);

void quicksort(void *arr, int size, int start, int end,
  int(*cmp)(const void*, const void*), void(*swp)(const void*, const void*))
{
  if (end<=start){
    return;
  }

  char *tevs = arr;

  char *pivot = tevs + start*size;

  int i = start - 1;
  int j = end + 1;

  while(1){
    do{
      j--;
    }while(cmp(tevs+j*size, pivot)>0);

    do{
      i++;
    }while(cmp(tevs+i*size,pivot)<0);

    if (i<j){
      swp(tevs+i*size,tevs+j*size);
    }else{
      break;
    }
  }

  printf("j = %d\n", j);

  quicksort(arr,size,start,j,cmp,swp);
  quicksort(arr,size,j + 1,end,cmp,swp);

/*
  for(i=1;i<len;i++){
    r = f(tevs,(tevs+size));
    tevs+=size;
    printf("%d\n",r);
  }
  */

}

void swap(const void *a, const void *b){
//  printf("swapping %d %d\n",*(int*)a,*(int*)b );
  int tmp = *(int*)a;
  *(int*)a = *(int*)b;
  *(int*)b = tmp;
}

int compare(const void *a, const void *b)
{
  return *(int*)a-*(int*)b;
}

int main()
{
  int i;


  unsigned int arr2[256] = {
    0,   8, 109, 220, 222, 241, 149, 107,  75, 248, 254, 140,  16,  66 ,
    74,  21, 211,  47,  80, 242, 154,  27, 205, 128, 161,  89,  77,  36 ,
    95, 110,  85,  48, 212, 140, 211, 249,  22,  79, 200,  50,  28, 188 ,
    52, 140, 202, 120,  68, 145,  62,  70, 184, 190,  91, 197, 152, 224 ,
    149, 104,  25, 178, 252, 182, 202, 182, 141, 197,   4,  81, 181, 242 ,
    145,  42,  39, 227, 156, 198, 225, 193, 219,  93, 122, 175, 249,   0 ,
    175, 143,  70, 239,  46, 246, 163,  53, 163, 109, 168, 135,   2, 235 ,
    25,  92,  20, 145, 138,  77,  69, 166,  78, 176, 173, 212, 166, 113 ,
    94, 161,  41,  50, 239,  49, 111, 164,  70,  60,   2,  37, 171,  75 ,
    136, 156,  11,  56,  42, 146, 138, 229,  73, 146,  77,  61,  98, 196 ,
    135, 106,  63, 197, 195,  86,  96, 203, 113, 101, 170, 247, 181, 113 ,
    80, 250, 108,   7, 255, 237, 129, 226,  79, 107, 112, 166, 103, 241 ,
    24, 223, 239, 120, 198,  58,  60,  82, 128,   3, 184,  66, 143, 224 ,
    145, 224,  81, 206, 163,  45,  63,  90, 168, 114,  59,  33, 159,  95 ,
    28, 139, 123,  98, 125, 196,  15,  70, 194, 253,  54,  14, 109, 226 ,
    71,  17, 161,  93, 186,  87, 244, 138,  20,  52, 123, 251,  26,  36 ,
    17,  46,  52, 231, 232,  76,  31, 221,  84,  37, 216, 165, 212, 106 ,
    197, 242,  98,  43,  39, 175, 254, 145, 190,  84, 118, 222, 187, 136 ,
    120, 163, 236, 249
};

  int LEN = 9;
  int arr[9] = {7,8,6,5,4,3,2,1,0};

  for(i = 0;i<LEN;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  quicksort(&arr,sizeof(int),0, LEN-1,compare, swap);

  for(i = 0;i<LEN;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");


  return 0;
}
