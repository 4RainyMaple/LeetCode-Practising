class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n - 1;
        int top = 0;
        int below = n - 1;
        int k = 1;
        vector<vector<int>> matrix(n,vector<int>(n));
        //不断缩进外圈
        while ( k <= n*n )
        {
            for ( int i = left; i <= right; i++ , k++ )
                matrix[top][i] = k;
            top++;
            for ( int i = top; i <= below; i++, k++ )
                matrix[i][right] = k;
            right--;
            for ( int i = right; i >= left; i--, k++ )
                matrix[below][i] = k;
            below--; 
            for ( int i = below; i >= top; i--, k++ )
                matrix[i][left] = k;
            left++;
        }
        return matrix;
    }
};
