class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start=0;
        int c=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][1]<=intervals[start][1])
            {
                c++;
                continue;
            }
if(intervals[i][0]==intervals[start][0] && intervals[i][1]>intervals[start][1])
        {
            c++;
            start=i;
        }
            else
            {
                start=i;
            }
        }
        return intervals.size()-c;
        
        
    }
};
