/*把这个问题想象为过河建桥。
不是在无路可走的那个位置造桥，而是当发现无路可走的时候，回到能跳到最远点的那个位置造桥。
在无路可走之前，我们只是在默默地收集信息。
当发现无路可走的时候，才从收集到的信息中，选择最远点造桥。*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int maxPos = 0; //在某个位置能跳最远的距离
        int end = 0;    //表示通过step步能达到最远的位置，判断是否需要下一次step
        for ( int i = 0; i < (int)nums.size() - 1; ++i )
        {
            //收集信息
            maxPos = max( maxPos, i + nums[i] );

            //走投无路了，找到合适的地方建桥
            if ( i == end )
            {
                ++step;
                end = maxPos;
            }
        }
        return step;
    }
};
