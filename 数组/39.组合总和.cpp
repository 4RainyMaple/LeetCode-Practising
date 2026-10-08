class Solution {
public:
    vector<vector<int>> ans;
    vector<int> state;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //避免重复的机制就是先排序，选过后的元素不再选比其小的
        sort( candidates.begin(), candidates.end() );
        combinationSum(candidates, target, 0);
        return ans;
    }

    void combinationSum(vector<int> & candidates, int target, int start)
    {
        if ( target == 0 )
        {
            ans.push_back(state);
            return;
        }
        //将后面的元素逐个插入state
        for ( int i = start; i < candidates.size(); i++ )
        {
            if ( target < candidates[i] )
                break;
            state.push_back(candidates[i]);
            //注意可选重复元素，因此下次起始位置是i
            combinationSum(candidates, target - candidates[i], i);
            state.pop_back();
        }
    }
};
