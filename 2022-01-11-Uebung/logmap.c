#include <stdio.h>

double logmap(int n, double r, double x0) {
    if (n == 0)
        return x0;

    return logmap(n - 1, r, (r * x0 * (1 - x0)));
}

double logmap_gouders(int n, double r, double x0) {
    if (n == 0)
        return x0;

    double xn = logmap(n - 1, r, x0);

    return r * xn * (1 - xn);
}

int main() {
    int n = 8;
    double r = 7.3;
    double x0 = 0.9758;
    printf("%2.21f \n", logmap(n, r, x0));
    printf("%2.21f \n", logmap_gouders(n, r, x0));

    return 0;
}