class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // 注意这题是越短越合法的变式
        return solve(nums, k) - solve(nums, k - 1);
    }

    int solve(vector<int> & nums, int k)
    {
        unordered_map<int,int> cnt;
        int left = 0, ans = 0;
        for ( int right = 0; right < nums.size(); right++ )
        {
            cnt[nums[right]]++;
            
            while ( cnt.size() > k )
            {
                if ( --cnt[nums[left]] == 0 )
                    cnt.erase(nums[left]);
                left++;
            }
            // 应选择从 left 之后的区间
            ans += right - left + 1;
        }
        return ans;
    }
};
