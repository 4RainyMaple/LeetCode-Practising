class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int cnt = 1;
        for ( int i = 1; i < s.size(); i++ )
        {
            if ( s[i] == s[i - 1] )
                cnt++;
            else
            {
                if ( cnt == k )
                    return true;
                cnt = 1;
            }
        }
        // 记得最后再检查一下
        if ( cnt == k )
            return true;

        return false;
    }
};
