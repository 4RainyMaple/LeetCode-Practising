class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //这里一定要先返回，否则后续进入死循环
        if ( k <= 1 )
            return 0;
        int left = 0;
        int n = (int)nums.size();
        size_t product = 1;
        int ans = 0;
        for ( int right = 0; right < n; right++ )
        {
            product *= nums[right];
            while ( product >= k )
                product /= nums[left++];
            //在这个区间任取左端点，均满足条件
            if ( product < k )
                ans += right - left + 1;
        }
        return ans;
    }
};
