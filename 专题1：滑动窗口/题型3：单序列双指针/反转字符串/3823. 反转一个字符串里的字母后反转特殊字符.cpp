class Solution {
public:
    string reverseByType(string s) {
        int left = 0;
        int right = s.size() - 1;
        // 反转字母
        while ( left < right )
        {
            while ( left < right && !isLetter(s[left]) )
                left++;
            while ( left < right && !isLetter(s[right]) )
                right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }

        // 翻转字符
        left = 0;
        right = s.size() - 1;
        while ( left < right )
        {
            while ( left < right && isLetter(s[left]) )
                left++;
            while ( left < right && isLetter(s[right]) )
                right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }

    bool isLetter(char c)
    {
        string s = "!@#$%^&*()";
        return find(s.begin(), s.end(), c) == s.end();
    }
};
