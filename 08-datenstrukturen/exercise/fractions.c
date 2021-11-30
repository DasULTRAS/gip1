#include <stdio.h>

typedef struct{
  /*
    z / n
  */
  int z;  //zähler
  int n;  //nenner
} fraction;

fraction addition_bruch(fraction b1, fraction b2){
  fraction produkt;
  if(b1.n == b2.n){
    produkt.n = b1.n;
    produkt.z = b1.z + b2.z;
  } else {
    produkt.n = b1.n * b2.n;
    produkt.z = b1.n*b2.z
               +b2.n*b1.z;
  }

  return produkt;
}

int main(){
  fraction f1 = {2,4};
  fraction f2 = {1,2};

  fraction f3 = addition_bruch(f1, f2);
  printf("%d / %d + %d / %d = %d / %d\n", f1.z, f1.n, f2.z, f2.n, f3.z, f3.n);

  return 0;
}
