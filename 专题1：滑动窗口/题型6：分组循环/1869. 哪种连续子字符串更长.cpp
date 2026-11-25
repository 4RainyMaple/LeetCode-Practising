class Solution {
public:
    bool checkZeroOnes(string s) {
        int cnt0 = 0;
        int cnt1 = 0;
        int maxcnt0 = 0;
        int maxcnt1 = 0;
        for ( const auto & c : s )
        {
            if ( c == '0' )
            {
                cnt0++;
                maxcnt0 = max(maxcnt0, cnt0);
                cnt1 = 0;
            }
                
            else
            {
                cnt1++;
                maxcnt1 = max(maxcnt1, cnt1);
                cnt0 = 0;
            }
                
        }
        return maxcnt1 > maxcnt0;
    }
};
