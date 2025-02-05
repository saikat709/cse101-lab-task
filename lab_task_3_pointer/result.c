#include <stdio.h>
#include <string.h>


int main(){
    char result[5][2][100] = {
        { "saikat", "A+" },
        { "darun", "A+" },
        { "abc",   "B+" },
        { "sakibsir", "A++"}
    };


    while( 1 ){
        char q[100];
        printf("Enter name to search: ");
        scanf("%[^\n]%*c", q);

        if ( strcmp( q, "quit" ) == 0 ){
            break;
        }
        int found = 0;
        for( int i = 0; i < 5; i++ ){
            if ( strcmp( result[i][0], q ) == 0 ){
                found = 1;
                printf("Result is: %s\n", result[i][1]);
                break;
            }
        }
        if ( !found ) printf("Not found.");
        printf("Result of: %s\n", q);
    }
}