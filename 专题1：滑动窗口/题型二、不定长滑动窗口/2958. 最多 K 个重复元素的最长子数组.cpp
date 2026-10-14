class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int left = 0;
        unordered_map<int,int> cnt;
        int ans = 0;
        for ( int right = 0; right < n; right++ )
        {
            cnt[nums[right]]++;
            while( cnt[nums[right]] > k )
                --cnt[nums[left++]];
            ans = max( ans, right - left + 1 );
        }
        return ans;
    }
};
