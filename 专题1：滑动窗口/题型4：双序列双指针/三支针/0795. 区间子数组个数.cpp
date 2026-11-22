class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int i0 = -1, i1 = -1;   // 初始化为 -1，这样没找到 > right 的部分也能算对

        // 枚举右端点
        for ( int i = 0; i < nums.size(); i++ )
        {
            if ( nums[i] > right )
                i1 = i;
            if ( nums[i] >= left )
                i0 = i;
            ans += i0 - i1;     // 左端点的种数
        }
        return ans;
    }
};
