#include <stdio.h>  

#include <stdlib.h>  

#include <string.h>  

int main() {  

FILE* input = fopen("input.txt", "r");  

FILE* output = fopen("output.txt", "w");  

char sym;  

int s = 0;  

int a = 1;  

int count = 0;  

while (1) {  

  sym = fgetc(input);  

  if (sym == EOF) {  

   break;  

  }  

  else if (sym == ' ') {  

   count += a;  

  }  

  else if (sym >= 32 && sym <= 126){  

   a = 0;  

   s += count;  

   count = 0;  

  }  

  else if (sym == '\n') {  

   count = 0;  

   a = 1;  

  }  

}  

fprintf(output, "%d", s);  

fclose(input);  

fclose(output);  

return 0;  

} 

 

 

 
