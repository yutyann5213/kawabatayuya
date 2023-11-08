#include <stdio.h>

int main(void){
  int data[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int n, i, j, temp;

  printf("---insertion sort---\nBefore : ");
  for(n=0; data[n]!='\0'; n++){
    printf("%d ",data[n]);
  }

  i = 1;
  while(i < n){
    temp = data[i];
    j = i - 1;
    while(j >= 0 && temp < data[j]){
      data[j+1] = data[j];
      j = j - 1;
    }
    data[j+1] = temp;
    i = i + 1;
  }

  printf("\nAfter  : ");
  for(n=0; data[n]!='\0'; n++){
    printf("%d ",data[n]);
  }

  return 0;
}