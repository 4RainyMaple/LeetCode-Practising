class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int left = 0, right = 1;
        while ( right < s.size() )
        {
            if ( s[right] != s[left] )
            {
                if ( right - left >= 3 )
                    ans.push_back({left, right - 1});
                left = right;
            }
            right++;
        }
        if ( right - left >= 3 )
            ans.push_back({left, right - 1});
        return ans;
    }
};
