class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k + 1);
    }

    int solve(vector<int> & nums, int k)
    {
        int ans = 0, left = 0, cnt = 0;
        for ( int right = 0; right < nums.size(); right++ )
        {
            cnt += nums[right] % 2;

            while ( cnt - nums[left] % 2 >= k )
                cnt -= nums[left++] % 2;
            
            if ( cnt >= k )
                ans += left + 1;    //当前 left 也是符合条件的
        }
        return ans;
    }
};
