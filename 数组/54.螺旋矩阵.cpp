class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();
        vector <int> ret;
        int left = 0;
        int right = cols - 1;
        int up = 0;
        int below = rows - 1;
        //矩阵行列小心搞反，上部元素的行数小于下部元素
        while ( left <= right && up <= below )
        {
            for ( int i = left; i <= right; ++i )
            {
                ret.push_back(matrix[up][i]);
            }
            //每一轮遍历完都要马上移动边界并检查，否则左右边界重合时会出问题
            ++up;
            if ( up > below )
                break;
            
            for ( int j = up; j <= below; ++j )
            {
                ret.push_back(matrix[j][right]);
            }
            --right;
            if ( left > right )
                break;
            
            for ( int i = right; i >= left; --i )
            {
                ret.push_back(matrix[below][i]);
            }
            --below;
            if ( up > below )
                break;

            for ( int j = below; j >= up; --j )
            {
                ret.push_back(matrix[j][left]);
            } 
            ++left;
            if ( left > right )
                break;
              
        }
        return ret;
    }
};
