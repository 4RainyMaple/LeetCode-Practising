class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for ( int i = 1; i < words.size(); i++ )
        {
            if ( !isAnagrams(words[i - 1], words[i]) )
                ans.push_back(words[i]);
        }
        return ans;
    }

    bool isAnagrams(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};
