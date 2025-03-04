#include <stdio.h>  
 
void PermutToInvtab(int a[], int b[], int n); 
 
void main() { 
 int n; 
 scanf("%d", &n); 
 int a[1000]; 
 for (int i = 0; i < n; ++i) 
  scanf("%d", &a[i]); 
 int b[1000]; 
 PermutToInvtab(a, b, n); 
 for (int i = 0; i < n; ++i) 
  printf("%d ", b[i]); 
 return; 
} 
 
void PermutToInvtab(int a[], int b[], int n) { 
 for (int i = 0; i < n; ++i)  
  b[i] = 0; 
 for (int i = 0; i < n; ++i) { 
  for (int j = 0; j < i; ++j) { 
   if (a[j] > a[i]) 
    ++b[a[i] - 1]; 
     
  } 
 } 
}
