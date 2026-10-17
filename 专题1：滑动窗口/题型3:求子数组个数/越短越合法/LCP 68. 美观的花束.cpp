class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        int ans = 0;
        int left = 0;
        unordered_map<int,int> num;
        for ( int right = 0; right < (int)flowers.size(); right++ )
        {
            num[flowers[right]]++;
            while ( num[flowers[right]] > cnt )
            {
                if (--num[flowers[left]] == 0 ) 
                    num.erase(flowers[left]);
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
