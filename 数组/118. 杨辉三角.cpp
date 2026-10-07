class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.resize( numRows );      //上来先扩容，否则没法访问
        for ( int i = 0; i < numRows; i++ )
        {
            ans[i].resize(i+1);     //还是要扩容
            ans[i][0] = ans[i][i] = 1;
            for ( int j = 1; j < i; j++ )
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j]; 
        }
        return ans;
    }
};
