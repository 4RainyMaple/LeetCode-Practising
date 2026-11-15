class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();    // 防止 K 很大的情况越界
      
        // 先分为两块后各自逆序，分为两块只需对整体逆序
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
