#include <stdio.h>

double f(double x) {
    return x*x + 2*x;
}

double right_riemann_sum(double (*f)(double), double a, double b, int n) {
    double delta_x = (b - a) / n;
    double sum_result = 0.0;

    for (int i = 1; i <= n; i++) {
        double x_i = a + i * delta_x;
        sum_result += f(x_i) * delta_x;
    }

    return sum_result;
}

int main() {
    double a = 1.0;
    double b = 4.0;
    int n = 6;

    double result = right_riemann_sum(f, a, b, n);
    printf("Right Riemann Sum: %lf\n", result);

    return 0;
}

