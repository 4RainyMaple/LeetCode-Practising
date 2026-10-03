//时间复杂度提示两次二分查找之和

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int mid;

        int upper = 0;
        int bottom = rows - 1;
        while ( upper <= bottom )
        {
            mid = ( upper + bottom ) / 2;
            if ( matrix[mid][0] == target )
                return true;
            else if ( matrix[mid][0] < target )
                upper = mid + 1;
            else 
                bottom = mid - 1;
        }

        //防越界
        if ( bottom < 0 )
            return false;
            
        //选择bottom所在那一行二分查找
        int left = 0;
        int right = cols - 1;
        while ( left <= right )
        {
            mid = ( left + right ) / 2;
            if ( matrix[bottom][mid] == target )
                return true;
            else if ( matrix[bottom][mid] < target )
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return false;
    }
};
