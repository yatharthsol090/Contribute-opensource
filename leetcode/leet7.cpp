class Solution {
public:
    int check(vector<vector<int>> &dun, int i, int j, vector<vector<int>> &dp ) {
        int m = dun.size();
        int n = dun[0].size();

        if(i == m-1 and j == n-1) return 1 - ((dun[i][j]>0)?0 : dun[i][j]);
        if(i == m or j == n) return 1e9;

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int x1 = INT_MAX, x2 = INT_MAX;
        x1 = check(dun, i+1, j, dp);
        x2 = check(dun, i, j+1, dp);
        
        return dp[i][j] = ((min(x1, x2) - dun[i][j]<=0)? 1: (min(x1, x2) - dun[i][j]));
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));

        int ans = check(dungeon, 0, 0, dp);

        cout<<ans<<"\n";
        return ans;
    }
};
