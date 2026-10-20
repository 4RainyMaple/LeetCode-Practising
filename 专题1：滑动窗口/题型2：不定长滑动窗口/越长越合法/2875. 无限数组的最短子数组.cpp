class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int left = 0;
        int n = (int)nums.size();
        long long sum = 0;
        int len = INT_MAX;
        long long total = 0;
        for ( int ele : nums )
            total += ele;

        //关键是：把 targrt 分为两部分，利用滑动窗口求余数部分
        int rem = target % total;
        for ( int right = 0; right <  2 * n; right++ )
        {
            sum += nums[right % n];

            while ( sum > rem )
            {    
                sum -= nums[left % n];
                left++;
            }

            if ( sum == rem )
                len = min ( len, right - left + 1 );
        }
        return len < INT_MAX ? len + ( target / total ) * n : -1;
    }
};
