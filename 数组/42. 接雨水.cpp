/*
双指针法：
分别记录左边和右边最高峰。
若height[left] <= height[right]，则必有leftMax <= rightMax。
分两种情况证明：
如果leftMax就是当前柱子，显然成立
如果leftMax是以前的柱子，那么left能达到当前位置，
肯定是因为过去leftMax那个位置的右边同时存在更高的柱子。
同理：若height[left] > height[right]，则必有leftMax > rightMax。
这样就可以直接计算当前柱子上方的容水量，因为另一边总可以兜住。
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0;
        int left = 0;
        int rightMax = 0;
        int right = (int)height.size() - 1;
        int area = 0;
        while ( left <= right )
        {
            //更新左右最大高度
            leftMax = max( leftMax, height[left] );
            rightMax = max( rightMax, height[right] );

            if ( height[left] <= height[right] )
            {
                //用左侧最高减去当前高度即可
                area += leftMax - height[left];
                left++;
            }
            else
            {
                area += rightMax - height[right];
                right--;
            }
        }
        return area;
    }
};
