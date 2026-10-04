class Solution {
public:
    vector <int> state;
    vector <vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        subsets( 0, nums );
        return ans;
    }

    void subsets(int cur, vector<int> & nums)
    {
        if ( cur == nums.size() )
        {
            ans.push_back(state);
            return;
        }
        //考虑每种元素是否装进state
        state.push_back(nums[cur]);
        subsets( cur + 1, nums );
        state.pop_back();   //由于每层递归都会删除最后元素，因此返回到当前最后元素就是刚增加的元素
        subsets( cur + 1, nums );
    }
};
