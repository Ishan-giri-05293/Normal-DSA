class Solution {
public:
    int numTrees(int n) {
        // dp[i] = # of unique BSTs using i nodes
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            long long ways = 0;
            for (int root = 1; root <= i; ++root) {
                int left = root - 1;
                int right = i - root;
                ways += dp[left] * dp[right];
            }
            dp[i] = ways;
        }

        return (int)dp[n];
    }
};
