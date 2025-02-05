#include <stdio.h>


int sum_up(int arr[], int ind ){

    int size = sizeof(arr)/sizeof(int);

    if ( ind >=  size) return 0;

    return arr[ind] + sum_up(arr, ind+1);
}

int main(){
    int arr[] = { 2, 3, 5, 6, 7, 9, 10 };

    printf("\n#### Sum: %d\n\n", sum_up(arr, 0));
    
    return 0;
}