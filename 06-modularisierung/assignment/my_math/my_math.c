#include "my_math.h"

unsigned int get_fibonacci_recursive(int n){
    if(n <= 1)
        return 1;
    
    return get_fibonacci_recursive(n-1) + get_fibonacci_recursive(n-2);
}

unsigned int get_factorial_recursive(int n){
    if(n <= 1)
        return 1;
    
    return get_factorial_recursive(n-1) * n;
}
