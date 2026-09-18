class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if ( nums.empty() )
            return { -1 , -1 };

        int start = -1 , end = -1;
        int left = 0 , right = nums.size() - 1;
        int mid;

        //找左值
        while ( left <= right )
        {
            mid = ( left + right ) / 2;
            if ( nums[mid] == target )  //左移区间
            {
                start = mid;
                right = mid - 1;
            }

            else if ( nums[mid] < target )
                left = mid + 1;

            else 
                right = mid - 1;
        }

        //找右值，注意left和right需要重新赋值
        left = 0;
        right = nums.size() - 1;
        while ( left <= right )
        {
            mid = ( left + right ) / 2;
            if ( nums[mid] == target )  //右移区间
            {
                end = mid;
                left = mid + 1;
            }

            else if ( nums[mid] < target )
                left = mid + 1;

            else 
                right = mid - 1;
        }

        return { start , end };
    }
};
