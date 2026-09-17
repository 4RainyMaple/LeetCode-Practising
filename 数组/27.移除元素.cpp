class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        int fast = 0;
        int slow = 0;
        int len = (int) nums.size();
        while ( fast < len )
        {
            if ( nums[fast] != val )
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
      //注意最后不要返回nums.size()
        return slow;
    }
};
