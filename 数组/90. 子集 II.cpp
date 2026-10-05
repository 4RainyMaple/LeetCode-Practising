class Solution {
public:
    vector <int> state;
    vector <vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort( nums.begin(), nums.end() );   //便于跳过相同元素
        subsetsWithDup(nums, 0);
        return ans;
    }

    void subsetsWithDup(vector<int>& nums, int left)
    {
        int len = (int)nums.size();
        if ( left == len )
        {
            ans.push_back(state);
            return;
        }

        //选中当前元素，后面相同的可以再选
        state.push_back(nums[left]);
        subsetsWithDup(nums, left + 1);
        //只要我们不选当前的元素，那后面相同的元素也不要选了
        state.pop_back();
        do{
            left++;
        }while( left > 0 && left < len && nums[left] == nums[left - 1]);
        subsetsWithDup(nums, left);
    }
};
