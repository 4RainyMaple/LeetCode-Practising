class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans = 0;
        int left = 0;
        int right = plants.size() - 1;
        int waterA = capacityA, waterB = capacityB;

        while ( left < right )
        {
            if ( plants[left] > waterA )
            {
                waterA = capacityA;
                ans++;
            }
            if ( plants[right] > waterB )
            {
                waterB = capacityB;
                ans++;
            }
            waterA -= plants[left++];
            waterB -= plants[right--];
        }

        if ( left == right )
            if ( max(waterA, waterB) < plants[left] )
                ans++;

        return ans;
    }
};
