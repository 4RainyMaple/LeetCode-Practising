class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        //先排序，这样最大最小值都很好找，而且删除元素也很容易
        sort(nums.begin(), nums.end());
        int maxLen = 0;
        int left = 0;
        int n = (int)nums.size();
        for ( int right = 0; right < n; right++ )
        {
            while ( (size_t)nums[left] * k < nums[right] )
                left++;
            
            maxLen = max( maxLen, right - left + 1 );
        }
        return n - maxLen;
    }
};
