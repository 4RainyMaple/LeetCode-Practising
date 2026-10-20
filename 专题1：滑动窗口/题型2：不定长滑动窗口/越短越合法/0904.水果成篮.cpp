//就是在找种类最多为2的最长子串

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int n = (int)fruits.size();
        unordered_map<int,int> cnt;
        int ans = 0;
        for ( int right = 0; right < n; right++ )
        {
            cnt[fruits[right]]++;
            while ( cnt.size() > 2 )
            {
                if( --cnt[fruits[left]] == 0 )
                    cnt.erase(fruits[left]);
                left++;
            }

            ans = max( ans, right - left + 1 );
        }
        return ans;
    }
};
