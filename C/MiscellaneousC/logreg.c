#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEARNING_RATE 0.01
#define MAX_ITERATIONS 1000
#define EPSILON 0.0001

// Structure for storing the dataset
typedef struct {
    double x1;
    double x2;
    int label;
} DataPoint;

// Sigmoid function
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Function to perform logistic regression
void logisticRegression(DataPoint *data, int num_samples, double *weights) {
    int converged = 0;
    int iterations = 0;
    double cost, prev_cost;

    while (!converged && iterations < MAX_ITERATIONS) {
        prev_cost = cost;
        cost = 0.0;

        // Update weights
        double gradient[3] = {0.0}; // Initialize gradient to 0
        for (int i = 0; i < num_samples; ++i) {
            double prediction = sigmoid(weights[0] + weights[1] * data[i].x1 + weights[2] * data[i].x2);
            double error = data[i].label - prediction;
            cost += -data[i].label * log(prediction) - (1 - data[i].label) * log(1 - prediction);

            gradient[0] += error;
            gradient[1] += error * data[i].x1;
            gradient[2] += error * data[i].x2;
        }

        // Update weights using gradient descent
        weights[0] += LEARNING_RATE * gradient[0];
        weights[1] += LEARNING_RATE * gradient[1];
        weights[2] += LEARNING_RATE * gradient[2];

        cost /= num_samples;

        // Check for convergence
        if (fabs(prev_cost - cost) < EPSILON) {
            converged = 1;
        }

        iterations++;
    }
}

int main() {
    // Sample dataset
    DataPoint data[] = {
        {2.0, 3.0, 1},
        {4.0, 5.0, 1},
        {1.0, 2.0, 0},
        {3.0, 4.0, 0}
    };

    int num_samples = sizeof(data) / sizeof(data[0]);

    // Initialize weights
    double weights[3] = {0.0}; // Bias, weight1, weight2

    // Perform logistic regression
    logisticRegression(data, num_samples, weights);

    // Display the learned weights
    printf("Learned weights: Bias = %lf, Weight1 = %lf, Weight2 = %lf\n", weights[0], weights[1], weights[2]);

    return 0;
}

