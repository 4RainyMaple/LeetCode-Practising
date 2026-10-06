class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = (int)nums.size();
        //简单情形直接返回提速
        if ( len <= 2 )
            return len;

        int slow = 0;
        int fast = 0;
        int count = 0;
        while ( fast < len )
        {
            if ( fast > 0 && nums[fast] == nums[fast-1] )
            {
                count++;
                if ( count <= 2 )
                {
                    nums[slow] = nums[fast];
                    slow++;
                }
            }
            else
            {
                count = 1;
                nums[slow] = nums[fast];
                    slow++;
            }
            fast++;
        }
        return slow;
    }
};
