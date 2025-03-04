#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct list { 
    int data; 
    struct list* next; 
} list; 
 
list* new_list(int data) { 
    list* sorted = (list*)malloc(sizeof(list)); 
 
    sorted->data = data; 
    sorted->next = NULL; 
    return sorted; 
} 
 
void insertNode(list** head, int data) { 
    list * sorted = new_list(data); 
 
    if (*head == NULL) { 
        *head = sorted; 
    } 
    else if (data < (*head)->data) { 
        sorted->next = *head; 
        *head = sorted; 
    } 
    else { 
        list* now = *head; 
        while (now->next != NULL && data > now->next->data) { 
            now = now->next; 
        } 
        if (now->next != NULL && data == now->next->data) { 
            free(sorted); 
            return; 
        } 
        sorted->next = now->next; 
        now->next = sorted; 
    } 
} 
 
void freeList(list* head) 
{ 
    list* p; 
    while (head != NULL) 
    { 
        p = head; 
        head = head->next; 
        free(p); 
    } 
} 
 
void printList(list* head) 
{ 
    list* now = head; 
    while (now != NULL) 
    { 
        if (now->next != NULL && now->data != now->next->data) 
            printf("%d ", now->data); 
        if (now->next == NULL) 
            printf("%d ", now->data); 
            now = now->next; 
    } 
    printf("\n"); 
} 
 
int main() 
{ 
    list* head = NULL; 
    int data; 
    while (scanf("%d", &data) == 1) 
    { 
        insertNode(&head, data); 
    } 
 
    printList(head); 
 
    freeList(head); 
 
    return 0; 
}

