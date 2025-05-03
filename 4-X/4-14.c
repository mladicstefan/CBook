#include <stdio.h>
#define swap(t, x, y) do { t _tmp = (x); (x) = (y); (y) = _tmp; } while (0)

int main(void) {
    int a = 5;
    int b = 10;

    printf("Before swap: a = %d, b = %d\n", a, b);

    swap(int, a, b);

    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}