class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        // 处理行
        for ( int i = 0; i < n; i++ )
        {
            int x = rowShift[i] % n;
            reverse(grid[i].begin(), grid[i].end());
            reverse(grid[i].end() - x, grid[i].end());
            reverse(grid[i].begin(), grid[i].end() - x);
        }
        
        // 处理列
        auto f = [&](int upper, int bottom, int j) {
            while ( upper < bottom )
                swap(grid[upper++][j], grid[bottom--][j]);
        };

        for ( int j = 0; j < n; j++ )
        {
            int y = colShift[j] % n;
            f(0, n - 1, j);
            f(n - y, n - 1, j);
            f(0, n - y - 1, j);
        }

        return grid;
    }
};
