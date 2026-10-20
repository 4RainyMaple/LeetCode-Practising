class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long curSum = 0;
        long long maxSum = 0;
        unordered_map<int,int> cnt; //注意原数组中可能有重复元素，故需要记录次数
        cnt.reserve(k);
        for ( int right = 0; right < nums.size(); right++ )
        {
            curSum += nums[right];
            cnt[nums[right]]++;
            
            if ( cnt.size() == k )  //无重复元素就记录
                maxSum = max( maxSum, curSum );

            int left = right - k + 1;
            if ( left >= 0 )
            {
                curSum -= nums[left];
                if ( --cnt[nums[left]] == 0 )
                    cnt.erase(nums[left]);
            }
        }
        return maxSum;
    }
};
