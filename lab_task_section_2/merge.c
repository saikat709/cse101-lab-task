#include <stdio.h>

int main(){

    int arr1[] = { 1, 4, 5, 7, 6, 2, 9, 4, 38 };
    int arr2[] = { 1, 3, 4, 5, 6, 2, 9, 4, 38 };

    int size1 = sizeof(arr1)/sizeof(int);
    int size2 = sizeof(arr2)/sizeof(int);

    int res_size = size1 + size2;
    int res_arr[res_size];

    // merge
    for ( int i = 0; i < res_size; i++ ){
        if ( i < size1 ) res_arr[i] = arr1[i];
        else res_arr[i] = arr2[i - size1];
    }


    // sort
    for ( int i = 0; i < res_size; i++ ){
        for ( int j = 0; j < res_size; j++ ){
            if ( res_arr[i] < res_arr[j] ) {
                int tmp = res_arr[i];
                res_arr[i] = res_arr[j];
                res_arr[j] = tmp;
            }
        }
    }

    // print
    for( int i = 0; i < res_size; i++ ) printf("%d ", res_arr[i]);
    printf("\n");

    return 0;
}