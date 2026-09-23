class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //建立一个哈希表，key值装nums的元素，value值装nums元素的下标
        map < int, int > hashTable;
        int len = (int)nums.size();
        //只需一层循环，时间复杂度O(N)
        for ( int i = 0; i< len; ++i )
        {
            //找找哈希表里面有没有符合条件的元素，若有则返回当前下标和对应下标
            auto itr = hashTable.find( target - nums[i] );
            if ( itr != hashTable.end() )
                return { i, hashTable[target - nums[i]] };
            //否则把当前元素集下标存进哈希表
            hashTable.insert( {nums[i], i} );
        } 
        return {};
    }
};
