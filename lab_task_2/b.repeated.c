#include <stdio.h>
#include <string.h>

int main(){
    char a[100] = "aabcccccaaba";  scanf("%[^\n]%*c", a);
    char res[110];
    int ind = 0;
    for( int i = 0; a[i] != '\0' ; ++i){
        int j = 1; 
        while( i < (int) strlen(a)-1 && a[i] == a[i+1] ){
            i++;
            j++;
        }
        res[ind++] = a[i];
        if ( j < 10 ){
            res[ind++] = j + '0';
        } else {
            res[ind++] = j/10 + '0';
            res[ind++] = j%10 + '0';
        }
    }
    res[ind++] = '\0';

    if ( strlen(res) <= strlen(a) ){
        printf("Result: %s\n", res);
    } else {
        printf("Result: %s\n", a);  
    }
    return 0;
}