class Solution {
public:
    vector<vector<int>> ans;
    vector<int> state;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end() );
        combinationSum2( candidates, target, 0 );
        return ans;
    }

    void combinationSum2(vector<int>& candidates, int target, int start)
    {
        if ( target == 0 )
        {
            ans.push_back(state);
            return;
        }
        for ( int i = start; i < candidates.size(); i++ )
        {
            /*注意这里是大于start，若刚进来的start位的元素和上一位相等也应考虑，
            否则将会漏掉相等元素同时参与的情况，而后面遍历到相等的元素就不予以考虑了，
            因为下面的递归环节已经算过一遍了*/
            if ( i > start && candidates[i] == candidates[i-1] )
                continue;
            if ( candidates[i] > target )
                break;
            state.push_back(candidates[i]);
            combinationSum2( candidates, target - candidates[i], i + 1 );
            state.pop_back();
        }
    }
};
