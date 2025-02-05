#include <stdio.h>


int sum_func(  int arr[], int ind ){
    int size = sizeof(arr)/sizeof(int);
    if ( ind >= size ) return 0;
    return arr[ind] + sum_func(arr, ind+1);
}

int main(){

    // freopen("output.txt", "w", stdout);
    
    int arr[] = { 3, 4, 5, 5, 6, 7 };
    printf( "Sum munually: %d\n", arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] );
    printf( "Sum recursively: %d\n", sum_func(arr, 0) );
    return 0;
}