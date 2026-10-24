class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int cnt = 0;
        while ( left < right )
        {
            while ( left < right && nums[right] == 0 )
                right--;
            while ( left < right && nums[left] != 0 )
                left++;

            // 进行完上面两个循环后要再检查一次，防 left = right 的情况
            if ( left < right )
            {
                left++;
                right--;
                cnt++;
            }
        }
        return cnt;
    }
};  
