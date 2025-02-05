#include <stdio.h>




int main(){
    int arr[] = { 3,5, 7, 8, 23, 78, 3, 5, 7, 4, 2, 6 };
    int size = sizeof(arr)/sizeof(int);
    int res_arr[size];

    for ( int i = 0; i < size; i++ ){
        for ( int j = 0; j < size; j++ ){
            if ( arr[i] < arr[j] ) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    // add odds
    int ind = 0;
    for( int i = 0; i < size; i++ ){
        if ( arr[i]%2 == 1){
            res_arr[ind++] = arr[i];
        }
    }

    // add evens
    for( int i = 0; i < size; i++ ){
        if ( arr[i]%2 == 0 ){
            res_arr[ind++] = arr[i];
        }
    }
    
    
    // print
    for( int i = 0; i < size; i++ ) printf("%d ", res_arr[i]);
    printf("\n");


    return 0;
}