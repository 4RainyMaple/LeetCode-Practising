/*
这题有坑：
不能直接拿“子数组中至少有 k 个不同的整数，其中至少有 k 个不同的满足条件的整数”
减去“子数组中至少有 k+1 个不同的整数，其中至少有 k+1 个不同的满足条件的整数”
这会把“子数组中至少有 k+1 个不同的整数，其中有 k 个不同的满足条件的整数”也算进来
正确的算法：
“子数组中至少有 k 个不同的整数，其中至少有 k 个不同的满足条件的整数”
减去
“子数组中至少有 k+1 个不同的整数，其中至少有 k 个不同的满足条件的整数”
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        // 按引用捕获当前环境中的变量
        auto solve = [&](int limit) -> long long{
            unordered_map<int,int> cnt;
            int left = 0, number = 0;
            long long ans = 0;
            for ( int right = 0; right < nums.size(); right++ )
            {
                if ( ++cnt[nums[right]] == m )
                    number++;
                while ( cnt.size() >= limit && number >= k )
                {
                    // 同步修改两个变量
                    if ( cnt[nums[left]]-- == m )
                        number--;
                    if ( cnt[nums[left]] == 0 )
                        cnt.erase(nums[left]);
                    left++;
                }
                ans += left;
            }
            return ans;
        }; 
        return solve(k) - solve(k + 1);
    }
};
