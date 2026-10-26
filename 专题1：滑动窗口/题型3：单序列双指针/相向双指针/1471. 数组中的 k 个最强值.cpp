class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = arr.size() - 1;
        int mid = arr[right / 2];
        vector<int> ans(k);
        int index = 0;
        while (index < k)
        {
            if ( arr[right] - mid >= mid - arr[left] )
                ans[index++] = arr[right--];
            else
                ans[index++] = arr[left++];
        }
        return ans;
    }
};
