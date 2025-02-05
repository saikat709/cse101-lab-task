#include <stdio.h>

int length(char s[]){
    int len = 0;
    while( s[len] != '\0' ) len++;
    return len;
}

int isEqual(){
    char a[] = "saikat";
    char b[] = "saikat";
    if ( length(a) != length(b) ){
        return 0;
    }

    for( int i = 0; i < length(a); ++i ){
        if ( a[i] != b[i] ) return 0;
    }
    return 1;
}

void addStrings(){
    char a[] = "saikat ";
    char b[] = "islam";

    int size_a = length(a);
    int size_b = length(b);

    char res[size_a+size_b+1];
    int ind = 0;

    for( int i = 0; a[i] != '\0'; ++i ) res[ind++] = a[i];
    for( int i = 0; b[i] != '\0'; ++i ) res[ind++] = b[i];
    res[ind++] = '\0';

    printf("%s\n", res);
}


int main(){
    addStrings();

    return 0;
}