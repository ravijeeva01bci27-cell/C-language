#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) {
    int temp_a = *a;
    int temp_b = *b;

    // Update a to be the sum
    *a = temp_a + temp_b;
    
    // Update b to be the absolute difference
    *b = abs(temp_a - temp_b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
