#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Lexicographically non-decreasing
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// 2. Lexicographically non-increasing
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Helper to count distinct characters
int count_distinct(const char* s) {
    int count = 0;
    int hash[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (hash[s[i] - 'a'] == 0) {
            hash[s[i] - 'a'] = 1;
            count++;
        }
    }
    return count;
}

// 3. Sort by number of distinct characters
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int res = count_distinct(a) - count_distinct(b);
    return (res == 0) ? lexicographic_sort(a, b) : res;
}

// 4. Sort by length
int sort_by_length(const char* a, const char* b) {
    int res = strlen(a) - strlen(b);
    return (res == 0) ? lexicographic_sort(a, b) : res;
}

// The generic sorting function
void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            // If cmp_func returns > 0, it means arr[i] > arr[j] based on our logic
            if (cmp_func(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
