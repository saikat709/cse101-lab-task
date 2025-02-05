#include <stdio.h>

int main(){

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 87, 30, 472, 74 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int res_arr[size];

    int left = 0, right = size - 1;

    // pairing
    for(int i = 0; i < size; ++i ){
        if ( i%2 == 0 ) res_arr[i] = arr[left++];
        else res_arr[i] = arr[right--];
    }

    // print 
    for( int i = 0; i < size; i++ ) printf("%d ", res_arr[i]);
    printf("\n");
}