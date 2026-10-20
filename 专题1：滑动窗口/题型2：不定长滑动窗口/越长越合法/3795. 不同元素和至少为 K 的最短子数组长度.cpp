class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int sum = 0;
        int left = 0;
        int ans = INT_MAX;
        unordered_map<int,int> cnt;
        int n = (int)nums.size();
        for ( int right = 0; right < n; right++ )
        {
            if ( cnt[nums[right]]++ == 0 )
                sum += nums[right];

            //每移动一次left就检查更新一次答案
            while ( sum >= k )
            {
                ans = min( ans, right - left + 1 );

                if ( --cnt[nums[left]] == 0 )
                    sum -= nums[left];
                left++;
            }
            
        }
        return ans <= n ? ans : -1;
    }
};
