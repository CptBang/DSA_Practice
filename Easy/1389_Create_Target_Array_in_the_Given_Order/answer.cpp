/*

create empty vector
push_back until the index array value is not 1 greater than the previous
 -> insert into the correct position and continue

create ret vector of size nums/index
if the value in ret vector is 0, set it equal to the value from nums
else insert value and chop off the end


*/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ret;
        ret.push_back(nums[0]);

        for (int i = 1; i < index.size(); i++) {
            ret.insert(ret.begin()+index[i], nums[i]);
        }

        return ret;
    }
};
