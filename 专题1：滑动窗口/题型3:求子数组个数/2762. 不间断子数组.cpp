class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int left = 0;
        map<int,int> cnt;
        for ( int right = 0; right < (int)nums.size(); right++ )
        {
            cnt[nums[right]]++;
            //注意：取最后一个元素是 rbegin 而不是 end
            while ( cnt.rbegin()->first - cnt.begin()->first > 2 )
            {
                if ( --cnt[nums[left]] == 0 )
                    cnt.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
