class Solution {
public:
    static bool comp(vector<int> &m, vector<int> &n)
    {
        return m[1]<n[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        
        sort(points.begin(), points.end(), comp);
        
        int arrows = 1;
        int last = points[0][1];
        
        for(int i=1; i<points.size(); i++)
        {
            if(points[i][0]>last)
            {
                arrows++;
                last = points[i][1];
            }
        }
        return arrows;
    }
};