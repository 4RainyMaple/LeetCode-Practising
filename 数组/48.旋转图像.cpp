class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        //一个位置顺时针旋转4次就会回到原点，故一个点带动四个点交换，需要写循环
        for ( int row = 0; row < n / 2; ++row )
        {
            for ( int col = 0; col < (n+1) / 2; ++col )
            //关于循环条件：（考虑对称性，row和col可以互换）
            //若n为偶数，则row < n/2 , col < n/2
            //若n为奇数，则row < n/2 + 1 , col < n/2
            //可将row条件统一为 row < (n+1)/2
            {
                int temp = matrix[n-1-col][row];
                matrix[n-1-col][row] = matrix[n-1-row][n-1-col];
                matrix[n-1-row][n-1-col] = matrix[col][n-1-row];
                matrix[col][n-1-row] = matrix[row][col];
                matrix[row][col] = temp;
            }
        }
    }
};
