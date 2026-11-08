class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftmax = 0;
        int rightmax = 0;
        int area = 0;
        while ( left <= right )
        {
            leftmax = max ( leftmax, height[left] );
            rightmax = max ( rightmax, height[right] );
            if ( leftmax <= rightmax )
            {
                area += leftmax - height[left];
                left++;
            }
            else
            {
                area += rightmax - height[right];
                right--;
            }
        }
        return area;
    }
};
