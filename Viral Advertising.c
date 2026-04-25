#include <stdio.h>
#include <math.h>

/*
 * Complete the 'viralAdvertising' function below.
 */
int viralAdvertising(int n) {
    int shared = 5;      // Initial recipients on Day 1
    int cumulative = 0;

    for (int day = 1; day <= n; day++) {
        // Half of the people who received it like it
        int liked = floor(shared / 2);
        
        // Add to the running total
        cumulative += liked;
        
        // Each person who liked it shares it with 3 friends for the next day
        shared = liked * 3;
    }

    return cumulative;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int result = viralAdvertising(n);
    printf("%d\n", result);

    return 0;
}
