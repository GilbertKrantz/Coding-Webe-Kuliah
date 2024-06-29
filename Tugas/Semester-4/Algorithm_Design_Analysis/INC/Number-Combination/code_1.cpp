#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

// Function to calculate the number of sequences
long long count_sequences(int N, int K) {
    // Initialize dp array
    long long *dp = (long long *)calloc(K + 1, sizeof(long long));
    dp[0] = 1;
    
    for (int n = 1; n <= N; ++n) {
        long long *new_dp = (long long *)calloc(K + 1, sizeof(long long));
        long long *prefix_sum = (long long *)calloc(K + 2, sizeof(long long));
        
        // Calculate prefix sums
        for (int k = 0; k <= K; ++k) {
            prefix_sum[k + 1] = (prefix_sum[k] + dp[k]) % MOD;
        }
        
        // Update new_dp array
        for (int k = 0; k <= K; ++k) {
            if (k >= n) {
                new_dp[k] = (prefix_sum[k + 1] - prefix_sum[k - n + 1] + MOD) % MOD;
            } else {
                new_dp[k] = prefix_sum[k + 1] % MOD;
            }
        }
        
        // Swap dp and new_dp
        free(dp);
        dp = new_dp;
        free(prefix_sum);
    }
    
    long long result = dp[K];
    free(dp);
    return result;
}

int main() {
    int N, K;
    printf("Enter N and K: ");
    scanf("%d %d", &N, &K);
    
    printf("%lld\n", count_sequences(N, K));
    
    return 0;
}
