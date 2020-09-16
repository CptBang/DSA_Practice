/*

search for target
compare target to num in 0th index
do binary search on row

*/



class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int target, int row) {
        int start = 0;
        int end = matrix[row].size()-1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int curr = matrix[row][mid];
            if (curr == target) {
                return true;
            }
            else if (target > curr) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            if (target <= matrix[i].back()) {
                return binarySearch(matrix, target, i);
            }
        }
        
        return false;
    }
};