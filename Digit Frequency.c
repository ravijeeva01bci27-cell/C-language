#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    
    // Read the string input
    scanf("%s", s);
    
    // Initialize frequency array for digits 0-9 with zeros
    int freq[10] = {0};
    
    // Iterate through the string
    for (int i = 0; i < strlen(s); i++) {
        // Check if the character is a digit
        if (s[i] >= '0' && s[i] <= '9') {
            // Map character '0'-'9' to index 0-9
            freq[s[i] - '0']++;
        }
    }
    
    // Print the frequencies separated by spaces
    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }
    
    free(s);
    return 0;
}
