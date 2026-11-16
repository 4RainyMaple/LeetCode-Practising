class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int j = 0;
        for ( int i = 0; i < s.size(); i++ )
        {
            if ( j < spaces.size() && i == spaces[j] )
            {
                ans += ' ';
                j++;
            }
            // 注意每轮都需要追加
            ans += s[i];
        }
        return ans;
    }
};
