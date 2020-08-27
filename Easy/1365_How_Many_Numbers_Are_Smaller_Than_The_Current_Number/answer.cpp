/*

naive: for loop within a for loop, keep a count of the numbers smaller than the index

make a map with value == index
sort vector, push onto return vector new sorted index value

*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret;
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        
        unordered_map<int, int> map;
        map[cp[0]] = 0;
        for (int i = 1; i < cp.size(); i++) {
            if (cp[i] > cp[i-1]) {
                map[cp[i]] = i;
            } 
        }
        
        for (int n : nums) {
            ret.push_back(map[n]);
        }
        
        return ret;
    }
};