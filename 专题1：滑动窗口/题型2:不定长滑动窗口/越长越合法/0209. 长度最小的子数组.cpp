class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        
        for ( int right = 0; right < n; right++ )
        {
            sum += nums[right];
            //为了防止left在满足条件后仍然移动一次，可以将left放入条件中判断
            while ( sum - nums[left] >= target )
                sum -= nums[left++];
            if ( sum >= target )
                ans = min ( ans, right - left + 1 );
        }
        return ans <= n ? ans : 0;
    }
};
