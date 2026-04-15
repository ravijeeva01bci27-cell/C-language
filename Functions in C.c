#include <stdio.h>

/* 
  Function to compare four integers and return the largest.
*/
int max_of_four(int a, int b, int c, int d) {
    int max = a;

    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
