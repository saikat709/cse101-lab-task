#include <stdio.h>

void swap(int * a, int * b){
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}

int main(){
    int x = 18, y = 28;

    printf("Before swaping: x = %d and y = %d\n", x, y);
    swap(&x, &y);
    printf("After swaping: x = %d and y = %d\n", x, y);

    return 0;
}