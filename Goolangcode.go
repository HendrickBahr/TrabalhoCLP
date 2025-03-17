package main

import (
    "fmt"
    "math/rand"
    "time"
)

const N = 100

func gaussElimination(a [N][N + 1]float64, x[N]float64) {
    for i := 0; i < N-1; i++ {
        for j := i + 1; j < N; j++ {
            factor := a[j][i] / a[i][i]
            for k := i; k <= N; k++ {
                a[j][k] -= factor * a[i][k]
            }
        }
    }
    for i := N - 1; i >= 0; i-- {
        x[i] = a[i][N]
        for j := i + 1; j < N; j++ {
            x[i] -= a[i][j] * x[j]
        }
        x[i] /= a[i][i]
    }
}

func main() {
    var a [N][N + 1]float64
    var x [N]float64

    rand.Seed(time.Now().UnixNano())
    for i := 0; i < N; i++ {
        for j := 0; j <= N; j++ {
            a[i][j] = float64(rand.Intn(100) + 1)
        }
    }

    start := time.Now()
    gaussElimination(&a, &x)
    duration := time.Since(start)

    fmt.Printf("Tempo em Golang: %v\n", duration)
}
