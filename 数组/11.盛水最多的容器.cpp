//双指针法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        int max = 0;
        while (left != right)
        {
            area = (right - left) * min( height[left], height[right] );
            if ( area > max )
                max = area;
            /*思路：将短板向中间靠拢，因为短板决定水量。
                若移动长板，则只会变小不会变大。
                只有移动短板，水量才可能增长。即使减小也没关系，因为已经记录下来最大值。*/
            if ( height[left] <= height[right] )
                ++left;
            else
                --right;
        }
        return max;
    }
};
