/*

sort, then see what is missing
arithmetic progression and print missing

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int max = n*(n+1)/2;
        int real = accumulate(nums.begin(), nums.end(), 0);
        
        return max - real;
    }
};