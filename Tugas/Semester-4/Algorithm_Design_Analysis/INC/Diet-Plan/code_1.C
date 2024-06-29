#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int max(int a, int b) {
    return a > b ? a : b;
}

// Make a function to calculate the best way to spend M money and K skip days in N days with the given array of prices
// Make the function use all K skips
int bestWay(int N, int M, int K, int arr[]) {

    if (N == 0 || (M == 0 && K == 0)) {
        return 0;
    } else if (N == 1) {
        if (M >= arr[0] || K > 0) {
            return 1;
        } else {
            return 0;
        }
    } else if (M == 0 && K != 0) {
        if (K < N) {
            return K;
        } else {
            return N;
        }
    } else if (M != 0 && K == 0) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
            if (sum > M) {
                return i;
            }
        }
        return N;
    }

    int dp[N][M + 1][K + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= K; k++) {
                if (i == 0) {
                    if (j >= arr[i] && k > 0) {
                        dp[i][j][k] = 1;
                    }
                } else {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= arr[i]) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - arr[i]][k] + 1);
                    }
                    if (k > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + 1);
                    }
                }
            }
        }
    }

    // Print the dp table
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j <= M; j++) {
    //         for (int k = 0; k <= K; k++) {
    //             printf("%d ", dp[i][j][k]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }

    return dp[N - 1][M][K] - 1;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int res = bestWay(N, M, K, arr);
    printf("%d\n", res);
}