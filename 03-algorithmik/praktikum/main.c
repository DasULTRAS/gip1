#include <stdio.h>

int sqrt_brute_force(int randicand){
    int current_root = randicand/2;

    while (current_root*current_root > randicand) {
        --current_root;
    }

    return current_root;
}

float sqrt_heron(int randicand){
    float max, min;
    min = 1;
    max = randicand;

    int i = 0;

    while((min/max) < 0.999998){

        /* Debug
        ++i;
        printf("Heron Schleife: %d \n", i);
        printf("Genauigkeit: %f \n", (min/max));
	*/

        max = (max+min) /2;
        min = randicand /max;
    }

    return max;
}

float sqrt_bisektion(int randicand){
    float min, max, avg;
    min = 1;
    max = randicand;

    int i = 0;

    while((min/max) < 0.999998){

        /* Debug
        ++i;
        printf("Bisektion Schleife: %d \n", i);
        printf("Genauigkeit: %f \n", (min/max));
	*/

        avg = (min+max)/2;
        if(avg*avg >randicand)
            max = avg;
        else
            min = avg;
    }

    return max;
}

int main(){
    int a, scanf_input;

    for(;;){
        printf("Geben Sie eine ganze Zahl ein:\n");
        scanf_input = scanf("%d", &a);


        if(scanf_input == EOF)
            break;
        else if(scanf_input != 1)
            return 1;

       	printf("a: %d, sqrt brute-force: %d, sqrt Heron: %f, sqrt Bisektion: %f\n", a, sqrt_brute_force(a), sqrt_heron(a), sqrt_bisektion(a));
        //printf("a: %d, sqrt Bisektion: %f\n", a, sqrt_bisektion(a));
        //printf("a: %d, sqrt Heron: %f\n", a, sqrt_heron(a));
        //printf("a: %d, sqrt brute-force: %d\n", a, sqrt_brute_force(a));
    }

    return 0;
}
