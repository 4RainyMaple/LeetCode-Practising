class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i = nums1.size() - 1, j = nums2.size() - 1;
        while ( i >= 0 && j >= 0 )
        {
            if ( i <= j && nums1[i] <= nums2[j] )
            {
                ans = max ( ans, j - i );
                i--;
            }
            else if ( i <= j && nums1[i] > nums2[j] )
                j--;
            else
                i--;
        }
        return ans;
    }
};
