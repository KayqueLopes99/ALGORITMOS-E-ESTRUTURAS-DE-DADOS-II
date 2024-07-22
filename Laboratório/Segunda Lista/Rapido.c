// #include <stdio.h>

// int f(int n){
//     if(n == 0){
//         return 1;
//     }
//     int x = f(n-1);
//     int y = 1/f(n-1);
//     //return f(n -1) + 1/f(n - 1);
//     return x + y;
// }

// int main(void){
//     f(20);

//     return 0;
// }

#include <stdio.h>


int cont = 0;

int f(int n) {
    
    if(n == 0){
        return 1;
    }
    cont++;

    return f(n - 1) + 1 / f(n - 1);
}

int main(void) {
    f(20);
    printf("A função f foi chamada %d vezes\n", cont);

    return 0;
}