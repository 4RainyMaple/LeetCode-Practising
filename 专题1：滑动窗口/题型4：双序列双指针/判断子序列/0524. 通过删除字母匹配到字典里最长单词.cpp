class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        ranges::sort(dictionary);
        string ans = "";
        for ( const auto & d : dictionary )
            if ( isSubString(d, s) && d.size() > ans.size() )
                ans = d;
        return ans;
    }

    bool isSubString(const string & s, const string & t)
    {
        int i = 0, j = 0;
        while ( i < s.size() && j < t.size() )
        {
            if ( s[i] == t[j] )
                i++;
            j++;
        }
        return i == s.size();
    }
};
