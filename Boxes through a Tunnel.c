#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 41

// Define the box structure
struct box {
    int length;
    int width;
    int height;
};

typedef struct box box;

// Function to calculate volume
int get_volume(box b) {
    return b.length * b.width * b.height;
}

// Function to check if a box can pass through the tunnel
int is_lower_than_max_height(box b) {
    if (b.height < MAX_HEIGHT) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    // Allocate memory for n boxes
    box *boxes = malloc(n * sizeof(box));
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
    }
    
    for (int i = 0; i < n; i++) {
        // If height is strictly less than 41, print its volume
        if (is_lower_than_max_height(boxes[i])) {
            printf("%d\n", get_volume(boxes[i]));
        }
    }
    
    free(boxes);
    return 0;
}
