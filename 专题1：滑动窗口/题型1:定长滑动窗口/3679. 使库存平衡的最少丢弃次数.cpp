class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        //简单情形直接返回
        if ( w <= m )
            return 0;
        //记录丢弃次数
        int abandon = 0;    
        //记录每种类型出现次数，提前预支空间
        unordered_map<int,int> cnt;     
        cnt.reserve(w);
        //记录窗口中的物品是否丢弃，提前预留空间
        vector<bool> saved;
        saved.resize(w);
        //进入滑动窗口
        int day = (int)arrivals.size();
        for ( int right = 0; right < day; right++ )
        {
            if ( ++cnt[arrivals[right]] > m )
            {
                cnt[arrivals[right]] = m;
                abandon++;
                saved[right % w] = false;   //用w取模，简化空间
            }
            else
                saved[right % w] = true;

            int left = right - w + 1;
            if ( left < 0 )
                continue;
            //某种物品数量减为零才在哈希表中删除
            if ( saved[left % w] && --cnt[arrivals[left]] == 0 )
                    cnt.erase(arrivals[left]);
            //所有离开的物品都置为丢弃false
            saved[left % w] = false;
        }
        return abandon;
    }
};
