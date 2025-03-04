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
    int count = 0, sum = 0, x; 
    list* head = NULL; 
    list* end = NULL; 
    while (scanf("%d", &x) != EOF) { 
        list* p = (list*)malloc(sizeof(list)); 
        p->data = x; 
        p->next = NULL; 
        if (head == NULL){ 
            head = p; 
            end = p; 
        } 
        else{ 
            end->next = p; 
            end = p; 
        } 
        sum += x; 
        count++; 
    } 
    int avg = sum / count; 
    list_free(head); 
    printf("%d", avg); 
    return 0; 
}

