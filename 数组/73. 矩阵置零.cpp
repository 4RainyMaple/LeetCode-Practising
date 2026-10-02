//用第0行和第0列来记录本行或本列是否需要置为0
//此时需要先记录第0行或第0列是否需要置为0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();
        bool row0_contains_0 = false;
        bool col0_contains_0 = false;

        //检查第0行
        for ( int i = 0; i < cols; i++ )
        {
            if ( matrix[0][i] == 0 )
            {
                row0_contains_0 = true;
                break;
            }
        }
        //检查第0列
        for ( int j = 0; j < rows; j++ )
        {
            if ( matrix[j][0] == 0 )
            {
                col0_contains_0 = true;
                break;
            }
        }

        //遍历数组，记录是否需要置0
        for ( int i = 1; i < cols; i++ )
            for ( int j = 1; j < rows; j++ )
                if ( matrix[j][i] == 0 )
                    matrix[j][0] = matrix[0][i] = 0;

        //再次遍历数组，将需要置0的置0
        for ( int i = 1; i < cols; i++ )
            for ( int j = 1; j < rows; j++ )
                if (  matrix[j][0] == 0 || matrix[0][i] == 0 )
                    matrix[j][i] = 0;

        //按需将第0行和第0列置0
        if ( row0_contains_0 )
            for ( int j = 0; j < cols; j++ )
                matrix[0][j] = 0;

        if ( col0_contains_0 )
            for ( int i = 0; i < rows; i++ )
                matrix[i][0] = 0;
    }
};
