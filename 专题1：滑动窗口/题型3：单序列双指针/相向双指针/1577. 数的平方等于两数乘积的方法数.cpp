class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return f(nums1, nums2) + f(nums2, nums1);
    }

    int f(vector<int>& nums1, vector<int>& nums2)
    {
        int cnt = 0;
        
        for ( int i = 0; i < nums1.size(); i++ )
        {
            int left = 0;
            int right = nums2.size() - 1;
            // 注意数据量
            long long target = 1LL * nums1[i] * nums1[i];
            while ( left < right )
            {
                long long product = 1LL * nums2[left] * nums2[right];
                
                if ( product == target )
                {
                    // 左右端点相等就找区间内组合
                    if ( nums2[left] == nums2[right] )
                    {
                        int len = right - left + 1;
                        cnt += len * ( len - 1 ) / 2;
                        break;
                    }
                    // 左右端点不相等就找左右各自相等的数量
                    else
                    {
                        int l = left, r = right;
                        int leftCnt = 0, rightCnt = 0;
                        while ( l < right && nums2[l] == nums2[left] )
                        {
                            l++;
                            leftCnt++;
                        }
                        while ( r > left && nums2[r] == nums2[right] )
                        {
                            r--;
                            rightCnt++;
                        }
                        left = l;
                        right = r;
                        cnt += leftCnt * rightCnt;
                    }
                }
                else if ( product > target )
                    right--;
                else
                    left++;
            }
        }
        return cnt;
    }
};
