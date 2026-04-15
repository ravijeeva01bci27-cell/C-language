#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    
    // Loop until all digits are processed
    while (n > 0) {
        // Add the last digit (n % 10) to sum
        sum += (n % 10);
        
        // Remove the last digit from n
        n = n / 10;
    }
    
    printf("%d\n", sum);
    
    return 0;
}
