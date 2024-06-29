#include <stdio.h>
#include <limits.h>

#define MAXN 1000

int max(int a, int b) {
    return a > b ? a : b;
}

// Function to calculate the maximum number of steps that can be taken
int calculateMaxSteps(int M, int K, int N, int arr[]) {
    int dp[MAXN + 1][MAXN + 1];

    // Initialize the dp array with a large negative number
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = -1;
        }
    }

    // Base case: 0 steps if no tasks are taken
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[i-1][j] != -1) {
                // If we pay for the i-th task
                if (M - arr[i-1] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
                }
                // If we skip the i-th task
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
    }

    // Find the maximum number of steps with at most K skips
    int maxSteps = 0;
    for (int j = 0; j <= K; j++) {
        maxSteps = max(maxSteps, dp[N][j]);
    }

    return maxSteps;
}

int main() {
    int M, K, N;
    printf("Enter the amount of money left (M): ");
    scanf("%d", &M);
    printf("Enter the number of skips left (K): ");
    scanf("%d", &K);
    printf("Enter the number of costs (N): ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the array of costs: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int result = calculateMaxSteps(M, K, N, arr);

    printf("The maximum number of steps that can be taken: %d\n", result);

    return 0;
}
