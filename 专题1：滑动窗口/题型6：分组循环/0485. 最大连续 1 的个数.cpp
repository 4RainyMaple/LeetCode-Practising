// 思维不要固化了

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        for ( int n : nums )
        {
            if (n)
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else
                cnt = 0;
        }
        return ans;
    }
};
