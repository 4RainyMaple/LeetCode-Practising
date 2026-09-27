class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //按每个区间的左值进行排序
        sort(intervals.begin(),intervals.end());
        vector <vector <int>> merged;
        int len = (int)intervals.size();
        
        for ( int i = 0; i < len; i++ )
        {
            int left = intervals[i][0];
            int right = intervals[i][1];

            //两个区间完全是间断的
            if ( merged.empty() || merged.back()[1] < left )
                merged.push_back(intervals[i]);
            //左值不减，只需更新右值
            else 
                merged.back()[1] = max( right, merged.back()[1] );
        }
        return merged;
    }
};
