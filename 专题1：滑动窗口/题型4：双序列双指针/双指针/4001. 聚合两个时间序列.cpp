class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int p1 = 0, p2 = 0;
        while ( p1 < series1.size() && p2 < series2.size() )
        {
            int timestamp = min(series1[p1][0], series2[p2][0]);
            ans.push_back({timestamp, series1[p1][1] + series2[p2][1]});
            if ( series1[p1][0] == series2[p2][0] )
            {
                p1++;
                p2++;
            }
                
            else if ( series1[p1][0] < series2[p2][0] )
                p1++;

            else
                p2++;
            
        } 
        if ( p1 == series1.size() )
            for (; p2 < series2.size(); p2++)
                ans.push_back({series2[p2][0], series2[p2][1]});
        else
            for (; p1 < series1.size(); p1++)
                ans.push_back({series1[p1][0], series1[p1][1]});
        return ans;
    }
};
