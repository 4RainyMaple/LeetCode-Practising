//由于选择数量不确定，嵌套for循环行不通，只能走递归

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> & candidates, int target) 
    {
        //避免重复的机制就是先排序，选过后的元素不再选比其小的
        sort( candidates.begin(), candidates.end() );
        vector<vector<int>> ret;
        vector <int> state;
        int start = 0;
        recursion(state, candidates, target, start, ret);
        return ret;
    }

    void recursion(vector<int> & state, vector<int>& candidates, int target, int start, vector<vector<int>> & ret)  //参数记得加引用
    {
        //基准情形
        if ( target == 0 )
        {
            ret.push_back(state);
            return;
        }

        for ( int i = start; i < (int)candidates.size(); ++i )
        {
            if ( candidates[i] > target )  //如果这轮加的数过大了也就没必要循环了，后面只会更大
                break;

            state.push_back(candidates[i]);
            recursion(state, candidates, target - candidates[i], i, ret);  //注意下次起始位置是i
            state.pop_back();          //把这次加进去的拿出来，去找下一个数加进来的情况
        }
    }
};
