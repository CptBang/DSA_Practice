/*

go through array nums and delete val from it without allocating new array
call delete everytime we see the value?


*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin()+i);
                i--;
            }
        }

        return nums.size();
    }
};
