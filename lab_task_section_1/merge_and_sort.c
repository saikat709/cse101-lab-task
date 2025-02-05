#include <stdio.h>

int main(){

    int a[] = { 10, 2, 3, 1, 5, 9 };
    int b[] = { 7, 3, 5, 8, 5 };

    int size_a = sizeof(a)/sizeof(int);
    int size_b = sizeof(b)/sizeof(int);
    int size = size_a + size_b;

    int new_arr[size];

    for( int i= 0; i < size; ++i ){

        if ( i < size_a ){
            new_arr[i] = a[i];
        } else {
            new_arr[i] = b[i-size_a];
        }
    }

    for (int i = 0; i < size - 1; i++){
        for( int j = i; j < size - 1; j ++ ){

            if( new_arr[j] < new_arr[i] ){

                int temp = new_arr[i];
                new_arr[i] = new_arr[j];
                new_arr[j] = temp;
            }
        }
    }

    for( int i =0; i<size; i++) printf("%d ", new_arr[i]);
    printf("\n");

}
