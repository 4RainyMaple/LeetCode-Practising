class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int pairs = 0, left = 0;
        long long ans = 0;
        unordered_map<int,int> cnt;
        for ( int right = 0; right < nums.size(); right++ )
        {
            // 删减的时候同步统计相等对数
            pairs += cnt[nums[right]]++;
            while ( pairs >= k )
                pairs -= --cnt[nums[left++]];

            ans += left;
        }
        return ans;
    }
};
