#include <stdio.h>
#include <string.h>

int main(){
    char a[100] = "listen";  scanf("%[^\n]%*c", a);
    char b[100] = "silent";  scanf("%[^\n]%*c", b);

    int size_a = strlen(a);
    int size_b = strlen(b);
    int cnt_a[26] = {};
    int cnt_b[26] = {};

    int is_anagram = 1;

    if( size_a != size_b ){
        printf("FALSE\n");
        return 0;
    }

    for( int i = 0; i < size_a; ++i ){
        cnt_a[a[i] - 'a']++;
    }

    for( int i = 0; i < size_b; ++i ){
        cnt_b[b[i] - 'a']++;
    }

    for( int i = 0; i < 26; ++i ){
        if ( cnt_a[i] != cnt_b[i] ) is_anagram = 0;
    }

    if ( is_anagram ) printf("TRUE\n");
    else printf("FALSE\n");

    return 0;
}