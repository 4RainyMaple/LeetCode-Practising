class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end() );
        vector <int> state;
        vector < vector<int> > ret;
        int start = 0;
        recursion( candidates, target, start, state, ret );
        return ret;
    }

    void recursion(vector<int>& candidates, int target, int start, vector <int> & state, vector < vector<int> > & ret)
    {
        if ( target == 0 )
        {
            ret.push_back(state);
            return;
        }

        
        for ( int i = start; i < (int)candidates.size(); ++i )
        {
            //它跳过的是换一个相等的数重新开始，不是继续加上一个相等的数
            if ( i > start && candidates[i] == candidates[i-1] )
                continue;
            if ( target < candidates[i] )
                break;

            state.push_back(candidates[i]);
            //为了防止同一元素被反复选中，下一次从下一位开始枚举
            recursion( candidates, target - candidates[i], i + 1, state, ret );
            state.pop_back();
        }
    }
};
