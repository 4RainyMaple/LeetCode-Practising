class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        int cnt0 = 0;
        int left = 0;
        int ans = 0;

        for ( int right = 0; right < n; right++ )
        {
            cnt0 += nums[right] ? 0 : 1;
            while ( cnt0 > 1 )
            {
                cnt0 -= nums[left] ? 0 : 1;
                left++;
            }
            //这里不管有没有0，子串长度都要减一
            ans = max(ans, right - left);
        }
        return ans;
    }
};
