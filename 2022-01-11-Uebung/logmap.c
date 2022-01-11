#include <stdio.h>

double logmap(int n, double r, double x0){
    if(n == 0)
        return x0;

    return logmap(n-1, r, (r * x0 * (1 - x0)));
}

double logmap_gouders(int n, double r, double x0){
    if(n == 0)
        return x0;

    double xn = logmap(n-1, r, x0);

    return r * xn * (1 - xn);
}

int main(){
    printf("%2.21f \n", logmap(8, 7.3, 0.9758));
    printf("%2.21f \n", logmap_gouders(8, 7.3, 0.9758));

    return 0;
}