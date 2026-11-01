class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = (int)nums.size();
        int j = 0;
        // 对于每一个 i，考察定长滑动窗口，用另一个变量 j 来添加元素
        for( int i = 0; i < n; i++ )
        {
            if ( nums[i] != key )
                continue;
            // 从上一次的终点开始遍历，第一次至少从0开始遍历
            j = max(j, i - k);
            while ( j <= min(n - 1, i + k) )
                ans.push_back(j++);
        }
        return ans;
    }
};
