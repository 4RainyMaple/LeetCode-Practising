class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        while ( right < s.size() )
        {
            while ( right < s.size() && s[right] != ' ' )
                right++;
            reverse( s.begin() + left, s.begin() + right );
            left = ++right;
        }
        return s;
    }
};
