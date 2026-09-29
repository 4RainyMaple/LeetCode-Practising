class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;        //表示融合区间S是否被放入
        vector<vector<int>> ans;    //建立新的容器装答案
        for ( const auto & interval : intervals )
        {
            //若当前区间完全在融合区间S的左侧，直接插入即可
            if ( interval[1] < left )
                ans.push_back(interval);

            //若当前区间完全在融合区间S的右侧，则往后的区间也在S右侧，就先把S插入（因为有升序要求），再把剩下的区间插入
            else if ( interval[0] > right )
            {
                if(!placed)
                {
                    ans.push_back({left,right});
                    placed = true;  //注意改标签，防止反复插入S
                }
                ans.push_back(interval);
            }

            //如果不是上面两种情况，那就要融合区间了
            else
            {
                left = min(left,interval[0]);
                right = max(right,interval[1]);
            }
        }
        //有可能经历完循环S还未被插入，比如intervals中所有区间都在S左侧的情况
        if (!placed)
            ans.push_back({left,right});    //newInterval还是可能会被修改，所以还是写作插入{left,right}

        return ans;
    }
};
