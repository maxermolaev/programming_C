#include <stdio.h> 
#include <malloc.h> 
 
typedef struct list { 
 int data; 
 struct list* next; 
} list; 
 
void list_free(list* head) { 
 list* p = head; 
 while (p != NULL) { 
  list* next = p->next; 
  free(p); 
  p = next; 
 } 
} 
 
int main(){ 
 int count = 0, x; 
 list* head = NULL; 
 while (scanf("%d", &x) != EOF) { 
  list* p = (list*)malloc(sizeof(list)); 
  p->data = x; 
  p->next = head; 
  head = p; 
 } 
    for (list* i = head; i != NULL; i = i->next) { 
        if ((i->data < 0) && (i->data % 7) == 0) { 
            count++; 
        } 
    } 
 list_free(head); 
 printf("%d", count); 
 return 0; 
}
   
