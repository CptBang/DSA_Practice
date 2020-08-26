/*

easiest solution - for loop within a for loop, and count the number of pairs as you go through, less space
faster - one for loop, one map<int, vector<int>>, put index into map
    instead of vector<int>, keep occurrences and calculate later
    

all combinations = n(n-1)/2
1 [0, 3, 4] = 3*2/2 = 3
2 [1] = 1*0/2 = 0
3 [2, 5] = 2*1/2 = 1

*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> occur;
        
        for (int n : nums) {
            occur[n]++;
        }
        
        int pairs = 0;
        for (int n : occur.end()) {
            pairs += n * (n - 1) / 2;
        }
        
        return pairs;
    }
};