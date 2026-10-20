class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = (int)s.size();
        int left = 0;
        int cnt0 = 0;
        int cnt1 = 0;
        int ans = 0;
        for ( int right = 0; right < n; right++ )
        {
            if ( s[right] == '0' )
                cnt0++;
            else
                cnt1++;

            while ( cnt0 > k && cnt1 > k )
            {
                if ( s[left] == '0' )
                    cnt0--;
                else
                    cnt1--;
                left++;
            }

            if ( cnt0 <= k || cnt1 <= k )
                ans += right - left + 1;
        }
        return ans;
    }
};
