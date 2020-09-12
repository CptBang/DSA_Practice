/*

go through vector and see if 1 exists, and just keep going?

*/



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ret = 1;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == ret) {
                ret++;
                i = 0;
            }
            else {
                i++;
            }
        }

        return ret;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i+1 != nums[i]) {
                return i+1;
            }
        }

        return nums.size() + 1;
    }
};
