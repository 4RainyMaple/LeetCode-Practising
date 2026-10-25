class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;
        // 收缩窗口，把离得近的留下，直到窗口大小为 k
        while ( right - left + 1 > k )
        {
            if ( abs(arr[left] - x) <= abs(arr[right] - x) )
                right--;
            else 
                left++;
        }
        vector<int> ans(k);
        for ( int i = 0; i < k; i++ )
            ans[i] = arr[left + i];
        return ans;
    }
};
