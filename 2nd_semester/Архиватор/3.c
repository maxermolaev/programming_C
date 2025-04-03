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
 
Heap * createHeap(size_t size) { 
    Heap * heap = (Heap *)malloc(sizeof(Heap)); 
    heap->len = 0; 
    heap->set = (HeapItem *)malloc(sizeof(HeapItem) * size); 
    return heap; 
} 
 
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
 
void fillHeap(Heap * heap, int * hist) { 
    for (int i = 0; i < 256; i++) 
        if (hist[i]) 
            push(heap, hist[i], (unsigned char)i); 
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
 
List * createNodes() { 
    List * nodes = (List *)malloc(sizeof(List)); 
    nodes->first = NULL; 
    return nodes; 
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
 
int CodeLenght(Node * T, Encoding * E, int * hist, Encoding * buff, int len) { 
    if (!T->left && !T->right) { 
        E[T->symbol].len = len; 
        for (int i = 0; i < len; i++) { 
            E[T->symbol].code[i] = buff->code[i]; 
        } 
        return len * hist[T->symbol]; 
    } 
    buff->code[len] = 0; 
    int leftLen = CodeLenght(T->left, E, hist, buff, len + 1); 
    buff->code[len] = 1; 
    int rightLen = CodeLenght(T->right, E, hist, buff, len + 1); 
    return leftLen + rightLen; 
} 
 
double InformationCapacity(int * hist, int fileSize) { 
    double infCap = 0; 
    for (int i = 0; i < 256; i++) 
        if (hist[i]) 
            infCap += -1 * (((double)hist[i]) / fileSize) * 
                      log2(((double)hist[i]) / fileSize); 
    return infCap; 
} 
 
double Redundancy(double infCap, double averageLenCodeWord) { 
    return 1 - infCap / averageLenCodeWord; 
} 
 
int main() { 
    freopen("input.txt", "r", stdin); 
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
 
    Encoding * encodings = (Encoding *)malloc(sizeof(Encoding) * 256); 
    for (int i = 0; i < 256; i++) { 
        encodings[i].len = 0; 
        encodings[i].size = 100000; 
        encodings[i].code = (unsigned char *)calloc(100000, sizeof(unsigned char)); 
    } 
    Encoding * buff = (Encoding *)malloc(sizeof(Encoding)); 
    buff->len = 0; 
    buff->size = 100000; 
    buff->code = (unsigned char *) calloc(100000, sizeof(unsigned char)); 
 
    int    codeLenght = CodeLenght(HuffmanTree, encodings, hist, buff, 0); 
    double informationCapacity = InformationCapacity(hist, fileSize); 
    double redundancy = Redundancy(informationCapacity, (double)codeLenght / fileSize); 
 
    /* Answer */ 
    for (int letter = 0; letter < 256; letter++) { 
        if (hist[letter]) { 
            printf("%d : ", letter); 
            for (int j = 0; j < encodings[letter].len; j++) { 
                printf("%d", encodings[letter].code[j]); 
            } 
            printf("\n"); 
        } 
    } 
    printf("Information capacity = %0.6f\n", informationCapacity); 
    printf("Input file size = %d\n", fileSize); 
    printf("Code length = %d\n", codeLenght); 
    printf("Redundancy = %0.6f\n", redundancy); 
 
    return 0; 
}

