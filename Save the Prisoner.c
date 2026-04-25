#include <stdio.h>

/*
 * Complete the 'saveThePrisoner' function below.
 */
int saveThePrisoner(int n, int m, int s) {
    // Calculate the position using modular arithmetic
    // We subtract 1 from 's' to treat the seats as 0 to n-1
    // We add (m - 1) sweets to find the final relative position
    int last_prisoner = (s + m - 1) % n;
    
    // If the result is 0, it means the last candy goes to the n-th prisoner
    if (last_prisoner == 0) {
        return n;
    }
    
    return last_prisoner;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    
    while (t--) {
        int n, m, s;
        scanf("%d %d %d", &n, &m, &s);
        printf("%d\n", saveThePrisoner(n, m, s));
    }
    
    return 0;
}
