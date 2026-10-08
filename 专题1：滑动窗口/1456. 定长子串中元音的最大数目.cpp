class Solution {
public:
    int maxVowels(string s, int k) {
        int maxNum = 0;
        int curNum = 0;
        for ( int right = 0; right < s.size(); right++ )
        {
            //右滑窗进入
            if ( s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' || s[right] == 'u' )
                curNum++;

            //判断是否存在左滑窗
            int left = right - k + 1;
            if ( left < 0 )
                continue;

            //在左滑窗离开前更新答案，否则可能丢失一个元音
            maxNum = max( maxNum, curNum );

            //左滑窗离开
            if ( s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' || s[left] == 'u' )
                curNum--;
            
        }
        return maxNum;
    }
};
