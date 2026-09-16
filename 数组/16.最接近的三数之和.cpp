//依旧双指针法
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int len = (int) nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        int thisSum;

        for ( int i = 0; i < len - 2; ++i )
        {
            //查重
            if ( i > 0 && nums[i] == nums[i-1] )
                continue;
            
            int left = i + 1;
            int right = len - 1;
            
            while ( left < right )
            {
                thisSum = nums[i] + nums[left] + nums[right];

                if ( abs ( target - thisSum ) < abs ( closestSum - target ) )
                    closestSum = thisSum;
                
                //大了就让右指针左移，小了就让左指针右移
                if ( thisSum < target )
                    ++left;

                else if ( thisSum > target )
                    --right;

                else 
                    return target;
            }
        }
        return closestSum;
    }
};
