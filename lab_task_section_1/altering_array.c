#include <stdio.h>

int main(){
    int a[] = { 3, 4, 5, 2, 1 };
    int b[] = { 7, 8, 4, 6 };


    int size = ( sizeof(a) + sizeof(b) )/sizeof(int);
    int res_arr[size];

    int left = 0;
    int right = sizeof(b)/sizeof(int) - 1;

    for( int i = 0; i < size; ++i ){
        if ( i%2 == 0 ) res_arr[i]  = a[left++];
        else res_arr[i] = b[right--];
    }

    for( int i = 0; i < size; i++ ){
        printf("%d ", res_arr[i]);
    }
    printf("\n");

    return 0;
}