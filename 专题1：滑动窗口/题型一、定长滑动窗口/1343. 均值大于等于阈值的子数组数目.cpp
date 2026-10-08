class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int target = threshold * k;
        int curSum = 0;
        int count = 0;
        for ( int right = 0; right < arr.size(); right++ )
        {
            curSum += arr[right];
            int left = right - k + 1;
            if ( left < 0 )
                continue;
            if ( curSum >= target )
                count++;
            curSum -= arr[left];
        }
        return count;
    }
};
