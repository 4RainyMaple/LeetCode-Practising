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
            if ( height[left] <= height[right] )
                ++left;
            else
                --right;
        }
        return max;
    }
};
