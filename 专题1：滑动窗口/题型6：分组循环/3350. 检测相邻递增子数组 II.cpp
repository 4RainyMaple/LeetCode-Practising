class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 1;
        int cnt = 1;
        int last = 1;
        for ( int i = 1; i < nums.size(); i++ )
        {
            if ( nums[i] > nums[i - 1] )
                cnt++;
            else
            {
                // 一种容易漏掉的情况就是一段很长的增区间，取一半可能也很长
                ans = max( ans, cnt / 2 );
                int tmp = min( cnt, last );
                ans = max(ans, tmp);
                last = cnt;
                cnt = 1;
            }
        }
        ans = max( ans, cnt / 2 );
        int tmp = min( cnt, last );
        ans = max(ans, tmp);
        return ans;
    }
};
