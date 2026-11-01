class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for ( int i = 0; i < n - 2; i++ )
        {
            if ( nums[i] == 0 )
                continue;
            int j = i + 1;
            for ( int k = i + 2; k < n; k++ )
            {
                while ( nums[i] + nums[j] <= nums[k] )
                    j++;
                ans += k - j;
            }
        }
        return ans;
    }
};
