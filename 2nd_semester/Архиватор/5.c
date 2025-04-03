#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
 
 
typedef struct encoding { 
    int len; 
    int size; 
    unsigned char * code; 
} Encoding; 
 
typedef struct node { 
    int frequency; 
    unsigned char symbol; 
    struct node * left; 
    struct node * right; 
 
    struct node * next; 
} Node; 
 
typedef struct list { 
    struct node * first; 
} List; 
 
typedef struct heapItem { 
    int frequency; 
    unsigned char symbol; 
} HeapItem; 
 
typedef struct heap { 
    int len; 
    HeapItem * set; 
} Heap; 
 
void swap(HeapItem * a, HeapItem * b) { 
    HeapItem c = * a; 
    * a = * b; 
    * b = c; 
} 
 
int parent(int i) { 
    return (i - 1) / 2; 
} 
 
int left(int i) { 
    return (2 * i + 1); 
} 
 
int right(int i) { 
    return (2 * i + 2); 
} 
 
HeapItem * give(Heap * heap, int i) { 
    return &heap->set[i]; 
} 
 
int compare(Heap * heap, int i, int j) { 
    return give(heap, i)->frequency < give(heap, j)->frequency || 
           ( 
                   give(heap, i)->frequency == give(heap, j)->frequency && 
                   give(heap, i)->symbol > give(heap, j)->symbol 
           ); 
} 
 
void siftUp(Heap * heap, int i) { 
    if (!i) return; 
    int p = parent(i); 
    if (compare(heap, i, p)) { 
        swap(give(heap, i), give(heap, p)); 
        siftUp(heap, p); 
    } 
} 
 
void siftDown(Heap * heap, int i) { 
    int l = left(i); 
    int r = right(i); 
    int t = i; 
    if (l < heap->len && compare(heap, l, i)) 
        t = l; 
    if (r < heap->len && compare(heap, r, t)) 
        t = r; 
    if (t != i) { 
        swap(give(heap, i), give(heap, t)); 
        siftDown(heap, t); 
    } 
} 
 
void push(Heap * heap, int frequency, unsigned char symbol) { 
    give(heap, heap->len)->frequency = frequency; 
    give(heap, heap->len)->symbol = symbol; 
    siftUp(heap, heap->len); 
    heap->len++; 
} 
 
void heapSort(Heap * heap) { 
    int len = heap->len; 
    for (int i = len - 1; i > 0; i--) { 
        swap(give(heap, i), give(heap, 0)); 
        heap->len--; 
        siftDown(heap, 0); 
    } 
    heap->len = len; 
} 
 
Heap * createHeap(size_t size) { 
    Heap * heap = (Heap *)malloc(sizeof(Heap)); 
    heap->len = 0; 
    heap->set = (HeapItem *)malloc(sizeof(HeapItem) * size); 
    return heap; 
} 
 
List * createNodes() { 
    List * nodes = (List *)malloc(sizeof(List)); 
    nodes->first = NULL; 
    return nodes; 
} 
 
Encoding * createEncodings(size_t size) { 
    Encoding * encodings = (Encoding *)malloc(sizeof(Encoding) * size); 
    for (int i = 0; i < size; i++) { 
        encodings[i].len = 0; 
        encodings[i].size = 8; 
        encodings[i].code = (unsigned char *)calloc(8, sizeof(unsigned char)); 
    } 
    return encodings; 
} 
 
void fillHeap(Heap * heap, int * hist) { 
    for (int i = 0; i < 256; i++) 
        if (hist[i]) 
            push(heap, hist[i], (unsigned char)i); 
} 
 
void fillNodes(List * nodes, Heap * heap) { 
    for (int i = 0; i < heap->len; i++) { 
        Node * a = (Node *)malloc(sizeof(Node)); 
        a->frequency = give(heap, i)->frequency; 
        a->symbol = give(heap, i)->symbol; 
        a->left = NULL; 
        a->right = NULL; 
 
        if (!nodes->first) { 
            nodes->first = a; 
            a->next = NULL; 
        } 
        else { 
            a->next = nodes->first; 
            nodes->first = a; 
        } 
    } 
} 
 
void insert(List * nodes, Node * a) { 
    Node * c = nodes->first; 
    Node * p = NULL; 
    while (c && (c->frequency <= a->frequency)) { 
        p = c; 
        c = p->next; 
    } 
    if (!p) { 
        a->next = c; 
        nodes->first = a; 
    } 
    else if (!c) { 
        p->next = a; 
    } 
    else { 
        p->next = a; 
        a->next = c; 
    } 
} 
 
Node * buildHuffmanTree(List * nodes, int len) { 
    while (len - 1) { 
        Node * f = nodes->first; 
        Node * s = nodes->first->next; 
 
        nodes->first = s->next; 
 
        f->next = NULL;
		s->next = NULL; 
 
        Node * a = (Node *)malloc(sizeof(Node)); 
        a->frequency = f->frequency + s->frequency; 
        a->symbol = 0; 
        a->left = s; 
        a->right = f; 
 
        a->next = NULL; 
 
        len--; 
 
        insert(nodes, a); 
    } 
    return nodes->first; 
} 
 
int checkLeaf(Node * T) { 
    if (!T->left && !T->right) 
        return 1; 
    return 0; 
} 
 
int CodeLenght(Node * T, Encoding * E, int * hist, Encoding * buff, int len) { 
    if (checkLeaf(T)) { 
        if (E[T->symbol].size < buff->size) { 
            E[T->symbol].size = buff->size; 
            E[T->symbol].code = (unsigned char *) realloc(E[T->symbol].code, sizeof(unsigned char) * buff->size); 
        } 
        E[T->symbol].len = len; 
        for (int i = 0; i < ceil((float)len / 8); i++) 
            E[T->symbol].code[i] = buff->code[i]; 
        return len * hist[T->symbol]; 
    } 
    if ((len / 8 + 2) == buff->size) { 
        buff->size *= 2; 
        buff->code = (unsigned char *) realloc(buff->code, sizeof(unsigned char) * buff->size); 
    } 
 
    buff->code[len / 8] &= ((unsigned char)255 - ((unsigned char)1 << (7 - (len % 8)))); 
    int depthLeft = CodeLenght(T->left, E, hist, buff, len + 1); 
 
    buff->code[len / 8] |= (unsigned char)1 << (7 - (len % 8)); 
    int depthRight = CodeLenght(T->right, E, hist, buff, len + 1); 
    return depthLeft + depthRight; 
} 
 
void printPrefTree(Node * T) { 
    if (checkLeaf(T)) { 
        printf("1"); 
        for (int i = 0; i < 8; i++) { 
            if (T->symbol & ((unsigned char)1 << (7 - i))) 
                printf("1"); 
            else 
                printf("0"); 
        } 
        return; 
    } 
    printf("0"); 
    printPrefTree(T->left); 
    printPrefTree(T->right); 
} 
 
void clear(Node * T) { 
    if (!T) 
        return; 
    if (T->left) 
        clear(T->left); 
    if (T->right) 
        clear(T->right); 
    free(T); 
} 
 
int main() { 
    freopen("input.bin", "rb", stdin); 
    freopen("output.txt", "w", stdout); 
 
    int fileSize = 0; 
    int hist[256] = {0}; 
 
    unsigned char symbol; 
    while (scanf("%c", &symbol) != EOF) { 
        fileSize++; 
        hist[symbol]++; 
    } 
    Heap * heap = createHeap(256); 
    fillHeap(heap, hist); 
    heapSort(heap); 
 
    List * nodes = createNodes(); 
    fillNodes(nodes, heap); 
 
    Node * HuffmanTree = buildHuffmanTree(nodes, heap->len); 
 
    Encoding * encodings = createEncodings(256); 
    Encoding * buff = createEncodings(1); 
 
    int codeLenght = CodeLenght(HuffmanTree, encodings, hist, buff, 0); 
 
    printPrefTree(HuffmanTree); 
  
    free(heap->set); 
    free(heap); 
    clear(HuffmanTree); 
    for (int i = 0; i < 256; i++) 
        free(encodings[i].code); 
    free(encodings); 
    free(buff->code); 
    free(buff); 
 
    return 0; 
}
