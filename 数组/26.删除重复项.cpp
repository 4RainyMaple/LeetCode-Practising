class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 1;
        int slow = 1;
        int len = nums.size();
        if ( len == 0 )
            return 0;
        while ( fast <= len - 1 )
        {
            //拿fast遍历数组，只要发现不重复的就让slow记下来再往前走
            if ( nums[fast] != nums[fast-1] )
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
