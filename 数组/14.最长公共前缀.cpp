class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        //LCP(S1...Sn) = LCP( LCP(S1...Sn-1) Sn )据此写递归
        if ( strs.size() == 0 )
            return "";

        string prefix = strs[0];
        for ( int i = 0; i < strs.size(); ++i )
        {
            prefix = longestCommonPrefix( prefix, strs[i] );
            if ( prefix.size() == 0 )
                break;
        }

        return prefix;
    }

    //利用重载写两个字符串的相同前缀（相当于递归的基准情况）
    string longestCommonPrefix( const string & str1, const string & str2  )
    {
        string prefix = "";
        int index = 0;
        while ( index != str1.size() && index != str2.size() )
        {
            if ( str1[index] == str2[index])
            {
                prefix += str1[index];
                ++index;
            }
            else
                break;
        }
        return prefix;
    }
};
