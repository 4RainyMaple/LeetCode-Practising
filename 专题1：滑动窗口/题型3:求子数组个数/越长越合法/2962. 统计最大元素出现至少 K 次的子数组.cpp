class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = ranges::max(nums);
        int cnt = 0;
        int left = 0;
        long long ans = 0;

        for ( int right = 0; right < (int)nums.size(); right++ )
        {
            if ( nums[right] == maxElement )
                cnt++;
            while ( cnt >= k )
                if ( nums[left++] == maxElement )
                    cnt--;
            ans += left;
        }
        return ans;
    }
};
