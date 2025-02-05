#include <stdio.h>

int main(){

    int arr[] = { 3,2,6,8,9 };
    int n = sizeof(arr)/sizeof(int);

    for (int i = 0; i<n; i++){
        for( int j = i; j < n; j ++ ){

            if( arr[i] > arr[j] ){

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for( int i =0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}