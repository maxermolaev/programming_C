#include <stdio.h> 
 
int R[301][301]; 
int N, M; 
 
void Is1234(int *n1, int *n2, int *n3, int *n4) { 
    *n1 = *n2 = *n3 = *n4 = 1; 
    for(int x = 1; x <= N; ++x) { 
        int s = 0, q = 0; 
        for(int y = 1; y <= N; ++y) { 
            s+= R[x][y]; 
            q+= R[y][x]; 
        } 
        if (*n1 && s >  1) *n1 = 0;    
        if (*n2 && s == 0) *n2 = 0;    
        if (*n3 && q >  1) *n3 = 0;    
        if (*n4 && q == 0) *n4 = 0;    
        if (*n1 == 0) *n2 = 0; 
        if (*n1 == 0) *n4 = 0; 
        if (*n1 == 0 && 
            *n2 == 0 && 
            *n3 == 0 && 
            *n4 == 0) break; 
    } 
} 
 
int main() { 
    scanf("%d %d",&N,&M); 
    for(int i = 0; i < M; ++i) { 
        int x,y; 
        scanf("%d %d",&x,&y); 
        R[x][y] = 1; 
    } 
    int n1, n2, n3, n4, n5; 
    Is1234(&n1,&n2,&n3,&n4); 
    n5 = n3 && n4; 
    if (n1+n2+n3+n4+n5==0) puts("0"); 
    else { 
        if (n1) printf("%d ",1); 
        if (n2) printf("%d ",2); 
        if (n3) printf("%d ",3); 
        if (n4) printf("%d ",4); 
        if (n5) printf("%d ",5); 
    } 
}
