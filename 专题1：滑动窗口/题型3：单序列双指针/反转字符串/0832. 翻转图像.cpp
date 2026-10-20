class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        // 翻转
        for ( int i = 0; i < n; i++ )
        {
            int left = 0;
            int right = n - 1;
            while ( left < right )
            {
                swap( image[i][left], image[i][right] );
                left++;
                right--;
            }
        }

        // 反转
        for ( int i = 0; i < n; i++ )
        {
            for ( int j = 0; j < n; j++ )
                image[i][j] = 1 - image[i][j];
        }

        return image;
    }
};
