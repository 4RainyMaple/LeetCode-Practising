class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int curSum = 0;
        int maxSum = 0;
        //这里我们虚构一个长度为k的滑窗，看最多有几个连续的黑块
        for ( int right = 0; right < blocks.size(); right++ )
        {
            curSum += blocks[right] == 'B';
            int left = right - k + 1;
            if ( left < 0 )
                continue;
            maxSum = max( maxSum, curSum );
            curSum -= blocks[left] == 'B';
        }
        //若有k个，那就不用操作，不然就补相应差值即可 
        return maxSum == k ? 0 : k - maxSum;
    }
};
