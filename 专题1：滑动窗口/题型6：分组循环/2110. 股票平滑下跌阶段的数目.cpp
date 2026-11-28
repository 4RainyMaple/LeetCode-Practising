class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int left = 0, right = 0;
        long long ans = 0;
        for (; right < prices.size(); right++ )
        {
            if ( right > 0 && prices[right] - prices[right - 1] != -1 )
            {
                left = right;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
