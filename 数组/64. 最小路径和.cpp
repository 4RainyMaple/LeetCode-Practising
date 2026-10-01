class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp (rows,vector<int>(cols));
        dp[0][0] = grid[0][0];
        for ( int i = 1; i < cols; i++ )
            dp[0][i] = dp[0][i-1] + grid[0][i];
        
        for ( int j = 1; j < rows; j++ )
            dp[j][0] = dp[j-1][0] + grid[j][0];

        for ( int i = 1; i < cols; i++ )
            for ( int j = 1; j < rows; j++ )
                dp[j][i] = grid[j][i] + min( dp[j-1][i], dp[j][i-1] );

        return dp[rows-1][cols-1];
    }
};
