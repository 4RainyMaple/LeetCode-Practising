class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        int num0 = 0;
        for ( int right = 0; right < (int)nums.size(); right++ )
        {
            if ( !nums[right] )
                num0++;
            
            while ( num0 > k )
            {
                if ( !nums[left] )
                    num0--;
                left++;
            }

            ans = max ( ans, right - left + 1 );
        }
        return ans;
    }
};
