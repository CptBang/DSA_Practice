/*

check if [i][1] >= [i+1][0] && [i][0] < [i+1][0]
    push into new vector
    
probably needs some sort of sort to make sure the values are in order first

code fairy, help!

*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        
        vector<vector<int>> ret;
        
        auto compare = [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<int> tempInt = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (tempInt[1] >= intervals[i][0]) {
                tempInt[0] = min(tempInt[0], intervals[i][0]);
                tempInt[1] = max(tempInt[1], intervals[i][1]);
            }
            else {
                ret.push_back(tempInt);
                tempInt = intervals[i];
            }
        }
        
        if (ret.empty() || tempInt != ret.back())
            ret.push_back(tempInt);
        
        return ret;
    }
};
