class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int left = 0;
        int right = n - 1;
        int l = pow( nums[left], 2 );
        int r = pow( nums[right], 2 );
        while ( left < right )
        {
            if ( l > r )
            {
                ans.push_back(l);
                left++;
                l = pow( nums[left], 2 );
            }
            else
            {
                ans.push_back(r);
                right--;
                r = pow( nums[right], 2 );
            }
        }
        
        // 左右指针重合需要专门拿出来处理，防左指针一直是 0 的情况，右指针减完后会越界
        if ( left == right )
            ans.push_back(r);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
