#include <stdio.h>
#include <stdlib.h>

void matrixRotation(int M, int N, int R, int **matrix) {
    int layers = (M < N ? M : N) / 2;
    int **result = malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) result[i] = malloc(N * sizeof(int));

    for (int l = 0; l < layers; l++) {
        int m = M - 2 * l;
        int n = N - 2 * l;
        int len = 2 * (m + n) - 4;
        int *layer = malloc(len * sizeof(int));
        int count = 0;

        // 1. Extract layer elements (Anti-clockwise order)
        // Top row (left to right)
        for (int j = l; j < l + n; j++) layer[count++] = matrix[l][j];
        // Right col (top to bottom)
        for (int i = l + 1; i < l + m; i++) layer[count++] = matrix[i][l + n - 1];
        // Bottom row (right to left)
        for (int j = l + n - 2; j >= l; j--) layer[count++] = matrix[l + m - 1][j];
        // Left col (bottom to top)
        for (int i = l + m - 2; i > l; i--) layer[count++] = matrix[i][l];

        // 2. Calculate shift
        int shift = R % len;

        // 3. Refill the result matrix with shifted indices
        count = 0;
        // Top row
        for (int j = l; j < l + n; j++) result[l][j] = layer[(count++ + shift) % len];
        // Right col
        for (int i = l + 1; i < l + m; i++) result[i][l + n - 1] = layer[(count++ + shift) % len];
        // Bottom row
        for (int j = l + n - 2; j >= l; j--) result[l + m - 1][j] = layer[(count++ + shift) % len];
        // Left col
        for (int i = l + m - 2; i > l; i--) result[i][l] = layer[(count++ + shift) % len];

        free(layer);
    }

    // Print result
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d%s", result[i][j], (j == N - 1 ? "" : " "));
        }
        printf("\n");
        free(result[i]);
    }
    free(result);
}

int main() {
    int m, n, r;
    if (scanf("%d %d %d", &m, &n, &r) != 3) return 0;

    int **matrix = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    matrixRotation(m, n, r, matrix);

    for (int i = 0; i < m; i++) free(matrix[i]);
    free(matrix);
    return 0;
}
