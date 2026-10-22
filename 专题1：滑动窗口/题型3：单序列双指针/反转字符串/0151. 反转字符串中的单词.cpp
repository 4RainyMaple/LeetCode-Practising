class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int left = 0, right = 0;

        while ( right < s.size() )
        {
            while ( right < s.size() && s[right] == ' ' )
                right++;
            // 此时 right 是下一个单词的起点
            left = right;
            while ( right < s.size() && s[right] != ' ' )
                right++;
            // 此时 right 是下一个单词后的第一个空格
            // 注意此时 right 是空格，left 必须严格小于 right 才能截取单词
            // 截取空串会导致输出第一个单词前多一个空格
            if ( left < right )
                words.push_back(s.substr(left, right - left));
        }
        string ans = "";
        for ( int i = words.size() - 1; i >= 0; i-- )
        {
            ans += words[i];
            if( i > 0 )
                ans += " ";
        }
        return ans;
    }
};
