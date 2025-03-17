#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void gaussElimination(double a[N][N+1], double x[N]) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double factor = a[j][i] / a[i][i];
            for (int k = i; k <= N; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

int main() {
    double a[N][N+1];
    double x[N];

    srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= N; j++)
            a[i][j] = rand() % 100 + 1;

    clock_t start = clock();
    gaussElimination(a, x);
    clock_t end = clock();

    printf("Tempo em C: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
