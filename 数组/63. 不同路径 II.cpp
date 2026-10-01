//关键通项公式：dp[j][i] = dp[j-1][i] + dp[j][i-1];

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp (rows,vector<int>(cols));

        //先遍历第0行和第0列，只要有障碍后续都不可行，方法数为0
        for ( int i = 0; i < cols; i++ )
        {
            if ( obstacleGrid[0][i] == 1 )
                break;
            dp[0][i] = 1;
        }

        for ( int j = 0; j < rows; j++ )
        {
            if ( obstacleGrid[j][0] == 1 )
                break;
            dp[j][0] = 1;
        }

        //计算每个位置的方法数
        for ( int i = 1; i < cols; i++ )
            for ( int j = 1; j < rows; j++ )            
                if ( obstacleGrid[j][i] == 0 )
                    dp[j][i] = dp[j-1][i] + dp[j][i-1];
                    
        return dp[rows-1][cols-1];
    }
};
