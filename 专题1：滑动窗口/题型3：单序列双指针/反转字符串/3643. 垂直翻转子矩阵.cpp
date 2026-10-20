class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int upper, bottom;
        for ( int i = y; i < y + k; i++ )
        {
            upper = x;
            bottom = x + k -1;
            while ( upper < bottom )
            {
                swap(grid[upper][i], grid[bottom][i]);
                upper++;
                bottom--;
            }
        }
        return grid;
    }
};
