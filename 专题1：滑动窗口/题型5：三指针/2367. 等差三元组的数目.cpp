class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while ( j < n && nums[j] - nums[i] < diff )
                j++;
            if ( j == n )
                break;
            if ( nums[j] - nums[i] > diff )
                continue;

            int k = n - 1;
            while ( k > j && nums[k] - nums[j] > diff )
                k--;
            // k == j 不要 break，后面还有机会
            if ( nums[k] - nums[j] < diff )
                continue;
            ans++;
        }
        return ans;
    }
};
