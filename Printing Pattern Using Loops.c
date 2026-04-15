#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int size = 2 * n - 1;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Find the minimum distance to any of the four edges
            int min = i < j ? i : j;
            min = min < size - i ? min : size - i - 1;
            min = min < size - j ? min : size - j - 1;
            
            // The value to print is n minus that minimum distance
            printf("%d ", n - min);
        }
        printf("\n");
    }
    
    return 0;
}
