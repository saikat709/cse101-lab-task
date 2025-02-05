#include <stdio.h>
#include <stdlib.h>

int main(){

    int size = 0;
    int ** graph;
    int * ad_sizes;
    printf("How to vertices you have? : "); scanf("%d", &size);

    graph = (int**) malloc( size * sizeof(int*) );
    ad_sizes = (int* ) malloc( size * sizeof(int) );

    for( int i = 0; i < size; i++ ){
        int ad_vertex = 0;
        printf("How many adjacent vertext %d have? : ", i+1);
        scanf("%d", &ad_vertex);

        graph[i] = (int*) malloc( ad_vertex * sizeof(int) );
        ad_sizes[i] = ad_vertex;

        for( int j = 0; j < ad_vertex; j++ ){
            printf("Adjacent vertext no. %d : ", j+1);
            scanf("%d", &graph[i][j]);
        }
    }

    // print
    for( int i = 0; i < size; i++ ){
        printf("%d |", i + 1 );
        for( int j = 0; j < ad_sizes[i]; j++ ){
            printf(" -> ");
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    // query
    while ( 1 ){
        int x, y;
        printf("Your query.... ( Write like p1 -> p1 ): \n");
        scanf("%d -> %d", &x, &y );

        int has_p2 = 0;
        for( int i = 0; i < ad_sizes[x - 1]; ++i ){
            printf("Check: %d, Y: %d\n", graph[x-1][i], y);
            if ( graph[x-1][i] == y ){
                has_p2 = 1;
                break;
            }
        }

        if ( has_p2 ) printf( "Connected.\n"  );
        else          printf( "Not Connected.\n" );
    }

    // free allocated memory
    for( int i = 0; i < size; i++ ){ free(graph[i]); }
    free(graph);

    return 0;
}