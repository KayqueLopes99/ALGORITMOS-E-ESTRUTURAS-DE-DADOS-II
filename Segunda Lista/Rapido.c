#include <stdio.h>


int f(int n) {
    

    if (n == 0) {
        return 1;
    }

    return f(n - 1) + 1 / f(n - 1);
}

int main() {
    f(20);
    return 0;
}
