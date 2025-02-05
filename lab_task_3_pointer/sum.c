#include <stdio.h>

double * sum(double * a, double * b){
    double * sumP;
    double sumVal; 
    sumP = &sumVal;
    * sumP = *a + *b;
    printf("Memory adress in local func: %p \n", sumP);
    return sumP;
}

int main(){
    double x = 5.3, y = 25;

    double * res = sum(&x, &y);
    printf("Indexing res pointer: %lf\n", res[1]);
    printf("Memory adress in main  func: %p \n", res);
    printf("Result: x + y = %lf \n", *res );

    return 0;
}