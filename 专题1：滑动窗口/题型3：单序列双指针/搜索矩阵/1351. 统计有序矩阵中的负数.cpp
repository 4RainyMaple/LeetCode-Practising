class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = n - 1;
        int cnt = 0;
        while ( i < m && j >= 0 )
        {
            if ( grid[i][j] < 0 )
            {
                // 若当前位置为负，则该列以下位置均为负，应向左继续搜索
                cnt += m - i;
                j--;
            }   
            else 
                // 若当前位置非负，则该列仍有可能存在负数，应向下继续搜索
                i++;
        }
        return cnt;
    }
};
