#include <stdio.h>

int main() {
    int a, b;
    scanf("%d\n%d", &a, &b);

    // Array to store English words for indices 1 to 9
    char *words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9) {
            // Print the word from the array
            printf("%s\n", words[i]);
        } else if (i > 9) {
            // Check if even or odd using the modulo operator
            if (i % 2 == 0) {
                printf("even\n");
            } else {
                printf("odd\n");
            }
        }
    }

    return 0;
}
