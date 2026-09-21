//双指针法

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = (int)nums.size();
        vector<vector<int>> ret;
        sort( nums.begin(), nums.end() );

        for ( int i = 0; i < len - 2; ++i )
        {
            //查重
            if ( i > 0 && nums[i] == nums[i-1] )
                continue;
            //考察最大最小值，省略不必要的循环
            if ( nums[i] + nums[i+1] + nums[i+2] > 0 )
                break;

            if ( nums[i] + nums[len-1] + nums[len-2] < 0 )
                continue;

            int left = i + 1;
            int right = len - 1;
            int sum;

            while ( left < right )
            {
                sum = nums[i] + nums[left] + nums[right];
                if ( sum == 0 )
                {
                    ret.push_back({ nums[i], nums[left], nums[right] });
                    //注意left和right也要查重
                    do{
                        ++left;
                    }while( left < right && nums[left] == nums[left-1] );

                    do{
                        --right;
                    }while( left < right && nums[right] == nums[right+1] );
                }

                else if ( sum < 0 )
                    do{
                        ++left;
                    }while( left < right && nums[left] == nums[left-1] );

                else
                    do{
                        --right;
                    }while( left < right && nums[right] == nums[right+1] );
            }
        }
        return ret;
    }
};
