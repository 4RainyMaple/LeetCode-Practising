class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0, left = 0;
        int n = nums.size();
        unordered_map<int,int> cnt;
        for ( int i = 0; i < n; i++ )
            cnt[nums[i]]++;
        int k = cnt.size();
        cnt.clear();
        
        for ( int right = 0; right < n; right++ )
        {
            cnt[nums[right]]++;
            while ( cnt.size() == k )
            {
                if ( --cnt[nums[left]] == 0 )
                    cnt.erase(nums[left]);
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
