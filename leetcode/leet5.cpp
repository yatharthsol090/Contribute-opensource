class Solution {
public:
    
    int solve(vector<string> &v, int i, int m, int n, vector<vector<vector<int>>> &dp) {
        if(i == v.size() or (m == 0 and n == 0)) {
            return 0;
        }
        if(dp[i][m][n] != -1) return dp[i][m][n];
        
        int zeros = 0, ones = 0;
        for(int j = 0; j < v[i].size(); j++) {
            if(v[i][j] == '1') ones++;
            if(v[i][j] == '0') zeros++;
        }
        
        int x1 = 0, x2 = 0;
        if(m >= zeros and n >= ones) x1 = 1 + solve(v, i+1, m - zeros, n-ones, dp);
        x2 = solve(v, i+1, m, n, dp);
                                                    
        return dp[i][m][n] = max(x1, x2);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        return solve(strs, 0, m, n, dp);
    }
};
