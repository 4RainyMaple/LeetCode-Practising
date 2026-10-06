class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len  = (int)nums.size();
        int left = 0;
        int right = len - 1;
        int mid;
        while ( left <= right )
        {
            mid = ( left + right ) / 2;
            if ( nums[mid] == target )
                return true;

            //这个题的不同在于重复元素会干扰判断哪边有序，那就把重复元素去掉就好
            if ( nums[mid] == nums[right] )
            {
                right--;
                continue;
            }

            if ( nums[mid] == nums[left] )
            {
                left++;
                continue;
            }

            if ( nums[mid] >= nums[left] )
            {
                if ( nums[left] <= target && target <= nums[mid] )
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if ( nums[mid] <= target && target <= nums[right] )
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};
