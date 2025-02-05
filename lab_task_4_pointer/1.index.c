#include <stdio.h>

int main(){

    int m, n, p;
    printf("m <space> n: "); scanf("%d %d", &m, &n);
    printf("p: "); scanf("%d", &p);

    if ( p <= 0 || p > m*n ){
        printf("Position must be between.\n");
        return 0;
    }

    int x = p%n == 0 && p > 0 ? p/n -1 : p/n;
    int y = p%n == 0 ? n-1 : p%n - 1;
    printf("INDEXING WOULD BE: [%d][%d]\n", x, y );
    return 0;
}