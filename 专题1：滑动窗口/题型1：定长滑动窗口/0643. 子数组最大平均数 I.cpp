class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int curSum = 0;
        int maxSum = INT_MIN;
        for ( int right = 0; right < nums.size(); right++ )
        {
            curSum += nums[right];
            
            int left = right - k + 1;
            if ( left < 0 )
                continue;

            maxSum = max ( maxSum, curSum );  //注意要在有完整窗口后才能更新答案，否则可能会出现上来一个正数，后面全是负数，导致maxSum偏大的情况
            curSum -= nums[left];
        }
        return (double)maxSum / k;
    }
};
