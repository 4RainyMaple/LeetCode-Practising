class Solution {
public:
    string reverseWords(string s) {
        int target;
        int left = 0, right = 0;
        // 先把 target 算出来
        while ( right < s.size() && s[right] != ' ' )
            right++;
        // 此时 right 是第一个单词后的空格
        target = vowelNum(s.substr(left, right - left + 1));
        
        while ( right < s.size() )
        {
            left = ++right;     // 此时 left 和 right 都是下一个单词的起点
            while ( right < s.size() && s[right] != ' ' )
                right++;
            // 此时 right 是单词后的空格
            if ( vowelNum(s.substr(left, right - left)) == target )
                reverse( s.begin() + left, s.begin() + right );
        }
        return s;
    }

    int vowelNum(const string & s)
    {
        int cnt = 0;
        for ( const auto & c : s )
            if ( isVowel(c) )
                cnt++;
        return cnt;
    }

    bool isVowel(const char & c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
