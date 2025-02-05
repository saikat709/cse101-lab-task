#include <stdio.h>
#include <string.h>

int main(){
    char a[100] = "saikat";    scanf("%[^\n]%*c", a);
    char b[100] = "sk*aikat";  scanf("%[^\n]%*c", b);
   
    int size_a = strlen(a), size_b = strlen(b);
    int is_equal = 1, i = 0, j = 0;

    for( i = 0,  j = 0; i < size_b && a[j] != '\0'; i++, j++ ){ // j for a, i for b

        if ( a[j] != b[i] && b[i+1] == '*' && a[j] == b[i+2] ) i += 2;  // handles saik, saii*k case

        if ( a[j] != b[i] && i < size_a - 1 && b[i+1] == '*'  ){ 
            i++; j--; 
        }
        else if ( !(b[i] == '.' || b[i] == '*' || b[i] == a[j] ) ) {
            is_equal = 0;
            break;
        }
        else if ( i < size_b - 1 && b[i+1] == '*' ){
            char start = b[i];
            while( a[j] != '\0' &&  a[j+1] == start ) j++;
            while( b[i] != '\0' && j + 1 >= i &&  ( b[i+1] == start || b[i+1] == '*' ) ) i++;
        }
    }

    while( i < size_b ){
        if ( b[i+1] == '*' ) i += 2;
        else {
            is_equal = 0;
            break;
        }
    }

    if ( j < size_a ) is_equal = 0;
    
    if( is_equal ) printf("TRUE\n");
    else printf("FALSE\n");

    return 0;
}