class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        //把每一项的差值（开销）装进一个新的数组里，然后做滑动窗口
        vector<int> d(n);
        for ( int i = 0; i < n; i++ )
            d[i] = abs(s[i] - t[i]);

        int ans = 0;
        int cost = 0;
        int left = 0;
        for ( int right = 0; right < n; right++ )
        {
            cost += d[right];
            while ( cost > maxCost )
            {
                cost -= d[left];
                left++;
            } 
            ans = max( ans, right - left + 1 );
        }
        return ans;
    }
};
