class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        for ( int i = 0; i < strs.size(); i++ )
        {
            // 注意这里一定要换为 int 不然会转化为无符号数比较
            if ( (int)strs[i].size() <= ans )
                continue;

            bool flag = true;   // 能不能更新答案
            for ( int j = 0; j < strs.size(); j++ )
            {
                if ( i != j && isSubStr(strs[i], strs[j]) )
                    flag = false;   // 当前字符串是其他字符串的子串就不能更新答案
            }
            if ( flag )
                ans = strs[i].size();
        }
        return ans;
    }
    bool isSubStr(const string & s1, const string s2)
    {
        int i = 0, j = 0;
        while ( i < s1.size() && j < s2.size() )
        {
            if ( s1[i] == s2[j] )
                i++;
            j++;
        }
        return i == s1.size();
    }
};
