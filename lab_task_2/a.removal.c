#include <stdio.h>
#include <string.h>

int main(){
    char a[100] = "saikat"; 
    char b[100] = "kat"; 
    char res[100];

    printf("String a: ");  scanf("%[^\n]%*c", a);
    printf("To remove: "); scanf("%[^\n]%*c", b);

    int size_a = strlen(a);
    int size_b = strlen(b);

    printf("%s\n", a);

    int index = 0;
    for( int i = 0, j = 0; i < size_a; ++i ){
        if ( b[j] == a[i] &&  i + size_b <= size_a ) {
            // confirm that it is full remove-sequence
            while( b[j] == a[i+j] && b[j] != '\0' ) j++;
            if ( j == size_b ) i += size_b;
        }
        res[index++] = a[i];
        j = 0;
    }
    res[index] = '\0';

    printf("Result: %s\n", res );
    return 0;
}
