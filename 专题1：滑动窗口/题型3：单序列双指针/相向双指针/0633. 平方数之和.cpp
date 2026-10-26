class Solution {
public:
    bool judgeSquareSum(int c) {
        int right = sqrt(c);
        int left = 0;
        while ( left <= right )
        {
            long long sum = 1LL * left * left + right * right;
            if ( sum < c )
                left++;
            else if ( sum > c )
                right--;
            else
                return true;
        }
        return false;
    }
};
