/*
从前向后遍历有可能会覆盖nums1中的元素，因此需要额外空间储存，空间复杂度为O(m+n)。
现在我们从后向前遍历，不需要额外空间，只需要两个指针，空间复杂度就降为O(1)。
但是从后向前会不会覆盖到原来的nums1呢？
设p1从m-1开始向前，p2从n-1开始向前。
则对于任意时刻，nums1后面会填充(m - 1 - p1)个nums1的元素，(n - 1 - p2)个nums2的元素，
而nums1在p1后是可填充的，共有(m + n - p1 - 1)个位置(注意p1是下标)，
显然 m + n - p1 - 1 > (m - 1 - p1) + (n - 1 - p2) 恒成立。
所以不必担心nums1前面的元素会被覆盖。
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if ( n == 0 )
            return;
        if ( m == 0 )
        {
            nums1 = nums2;
            return;
        }
        int p1 = m - 1;
        int p2 = n - 1;
        int pos = m + n - 1;
        while ( p1 >= 0 && p2 >= 0 )
        {
            if ( nums1[p1] >= nums2[p2] )
            {
                nums1[pos] = nums1[p1];
                p1--;
            }
            else
            {
                nums1[pos] = nums2[p2];
                p2--;
            }
            pos--;
        }
        if ( p1 < 0 )
            while ( p2 >= 0 )
            {
                nums1[pos] = nums2[p2];
                p2--;
                pos--;
            }

        else
            while ( p1 >= 0 )
            {
                nums1[pos] = nums1[p1];
                p1--;
                pos--;
            }
        
    }
};
