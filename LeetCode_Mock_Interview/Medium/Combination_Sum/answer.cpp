/*

go through candidates and add up to target using backtracking
sort candidates to make sure it's in order

*/



class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int index, vector<int> curr, vector<vector<int>> &ret) {
        if (target == 0) {
            ret.push_back(curr);
            return ;
        }
        else if (target < 0) {
            return ;
        }

        for (int i = index; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i, curr, ret);
            curr.pop_back();
        }

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, {}, ret);

        return ret;
    }
};
