#include <stdio.h>
#include <stdlib.h>

int main(){

    int m, n, count, productSum;
    int ** arr1, ** arr2, **result;
    printf("m <spoace> n: "); scanf("%d %d", &m, &n);

    if ( m != n ) {
        printf("Multiplication is not possible for this dimension.\n");
        return 0;
    }

    arr1   = (int**) malloc( m * sizeof(int*) );
    arr2   = (int**) malloc( m * sizeof(int*) );
    result = (int**) malloc( m * sizeof(int*) );

    // allocate memory
    for (int i = 0; i < m; i++)
        arr1[i] = (int*) malloc( n * sizeof(int) );

    for (int i = 0; i < m; i++)
        arr2[i] = (int*) malloc( n * sizeof(int) );

    for (int i = 0; i < m; i++)
        result[i] = (int*) malloc( n * sizeof(int) );

    // populating memory
    count = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) arr1[i][j] = ++count;
    }

    count = m*n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) arr2[i][j] = count--;
    }


    // multiplication
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            productSum = 0;
            for ( int k = 0; k < n; k++ ){ // one column
                productSum += arr1[i][k] * arr2[k][j];
                // printf("DEBUG: %d  %d\n", arr1[i][k], arr2[k][j]);
            }
            printf("\n");
            result[i][j] = productSum;
        }
    }

    // printing the matrix
    printf("ARRAY 1: \n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\nARRAY 2: \n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    printf("\nResult Array: \n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }


    // Free allocated memory
    for (int i = 0; i < m; i++) free(arr1[i]);
    free(arr1);

    for (int i = 0; i < m; i++) free(arr2[i]);
    free(arr2);

    for (int i = 0; i < m; i++) free(result[i]);
    free(result);

    return 0;
}