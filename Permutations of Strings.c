#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Transforms the array into the next lexicographical permutation.
 * Returns 1 if a next permutation exists, 0 otherwise.
 */
int next_permutation(int n, char **s) {
    // 1. Find the largest index i such that s[i] < s[i+1]
    int i = n - 2;
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0) {
        i--;
    }

    // If no such index exists, we are at the last permutation
    if (i < 0) return 0;

    // 2. Find the largest index j > i such that s[i] < s[j]
    int j = n - 1;
    while (strcmp(s[i], s[j]) >= 0) {
        j--;
    }

    // 3. Swap s[i] and s[j]
    char *tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;

    // 4. Reverse the sequence from s[i+1] to the end
    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    char **s = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        s[i] = malloc(11 * sizeof(char));
        scanf("%s", s[i]);
    }

    // The input is guaranteed to be sorted, so we print it first
    do {
        for (int i = 0; i < n; i++) {
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
        }
    } while (next_permutation(n, s));

    for (int i = 0; i < n; i++) free(s[i]);
    free(s);
    return 0;
}
