#include <stdio.h>

int main() {
    int n, m;
    float f1, f2;

    // Read two integers
    scanf("%d %d", &n, &m);
    // Read two floats
    scanf("%f %f", &f1, &f2);

    // Integer sum and difference
    printf("%d %d\n", n + m, n - m);
    
    // Float sum and difference (rounded to 1 decimal place)
    printf("%.1f %.1f\n", f1 + f2, f1 - f2);

    return 0;
}
