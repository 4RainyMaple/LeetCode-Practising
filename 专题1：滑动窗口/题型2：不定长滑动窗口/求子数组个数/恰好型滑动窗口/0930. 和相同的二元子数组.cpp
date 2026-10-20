class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 转换为计算子串和 >= goal和 >= goal+1 的数目，然后做差
        return solve(nums, goal) - solve(nums, goal + 1);
    }

    int solve( vector<int> & nums, int k )
    {
        int left = 0, ans = 0, sum = 0, n = nums.size();
        if ( k == 0 )
            return ( n + 1 ) * n / 2;
        for ( int right = 0; right < n; right++ )
        {
            sum += nums[right];
            while ( sum - nums[left] >= k )
                sum -= nums[left++];

            if ( sum >= k )
                ans += left + 1;
        }
        return ans;
    }
};
