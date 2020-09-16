/*

For each time, add the difference between it and the next up to the duration

ret += min(duration, timeSeries[i+1] - timeSeries[i])

ret = duration

*/


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }
        
        int ret = duration;
        
        for (int i = 0; i < timeSeries.size()-1; i++) {
            ret += min(duration, timeSeries[i+1] - timeSeries[i]);
        }
        
        return ret;
    }
};